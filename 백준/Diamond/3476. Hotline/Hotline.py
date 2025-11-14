import sys

# def print(*args, end='\n'):
#    f.write(' '.join(args) + end)

# f = open('d:/desktop/3476.out', 'w', encoding='utf-8')

def cmp(sub, pos_pred, pos_sub, neg_pred, neg_sub, om):
    def ret(x):
        x = x[:-1]
        a = 1e9
        if 'everybody' in (pos_sub[x] if x in pos_sub else []) + (neg_sub[x] if x in neg_sub else []):
            a = min(a, om[('everybody', *x)])
        if sub in (pos_sub[x] if x in pos_sub else []) + (neg_sub[x] if x in neg_sub else []):
            a = min(a, om[(sub, *x)])
        return a
    return ret

t = int(input())
for _ in range(t):
    print(f'Dialogue #{_ + 1}:')
    pos_pred = { 'everybody': [] } # sub: pred
    neg_pred = { 'everybody': [] } # sub: pred
    pos_sub = {} # pred: sub
    neg_sub = {} # pred: sub
    has_cont = 0
    order = 0
    om = {}
    while 1:
        order += 1
        sen = input().strip()
        stype = {'.': 0, '?': 1, '!': 2}[sen[-1]]
        if stype == 2:
            print(sen + '\n')
            break
        sen = sen.split()
        sub = sen[0]
        if sub == 'You': sub = 'you'
        idx = 1
        if stype == 0: # statement
            is_neg = 0
            has_obj = 1
            obj = ""
            pred = sen[idx]
            if pred in ["don't", "doesn't"]:
                is_neg = 1
                idx += 1
                pred = sen[idx]
                
            if pred[-1] == '.':
                pred = pred[:-1]
                has_obj = 0
                
            if sub not in ["I", "you"] and is_neg == 0:
                pred = pred[:-1]
                
            if sub == 'I':
                sub = 'you'
            elif sub == 'you':
                sub = 'I'
                
            if has_obj:
                obj = ' '.join(sen[idx + 1:])[:-1]

            if sub == 'nobody':
                sub = 'everybody'
                is_neg = 1
            
            if is_neg == 0:
                if not sub in pos_pred:
                    pos_pred[sub] = []
                pos_pred[sub].append((pred, obj))
                if (sub in neg_pred and (pred, obj) in neg_pred[sub]) or (pred, obj) in neg_pred['everybody']:
                     has_cont = 1
                if sub == 'everybody' and (pred, obj) in neg_sub:
                    has_cont = 1
                if not (pred, obj) in pos_sub:
                    pos_sub[(pred, obj)] = []
                pos_sub[(pred, obj)].append(sub)
            else:
                if not sub in neg_pred:
                    neg_pred[sub] = []
                neg_pred[sub].append((pred, obj))
                if (sub in pos_pred and (pred, obj) in pos_pred[sub]) or (pred, obj) in pos_pred['everybody']:
                     has_cont = 1
                if sub == 'everybody' and (pred, obj) in pos_sub:
                    has_cont = 1
                if not (pred, obj) in neg_sub:
                    neg_sub[(pred, obj)] = []
                neg_sub[(pred, obj)].append(sub)
            om[(sub, pred, obj)] = order
            # print((sub, pred, obj))
            
        if stype == 1: # question
            print(' '.join(sen))
            if has_cont:
                print("I am abroad.\n")
                continue
            if sub in ['do', 'does']:
                sub = sen[1]
                pred = sen[2]
                obj = ""
                if sub == 'I':
                    sub = 'you'
                elif sub == 'you':
                    sub = 'I'
                if pred[-1] == '?':
                    pred = pred[:-1]
                else:
                    obj = ' '.join(sen[3:])[:-1]
                if (pred, obj) in pos_sub and (sub in pos_sub[(pred, obj)] or 'everybody' in pos_sub[(pred, obj)]):
                    if not sub in ['I', 'you']:
                        pred = pred + 's'
                    print('yes,', sub, pred, end='')
                    if obj: print(' ' + obj + '.')
                    else: print('.')
                elif (pred, obj) in neg_sub and (sub in neg_sub[(pred, obj)] or 'everybody' in neg_sub[(pred, obj)]):
                    if not sub in ['I', 'you']:
                        pred = "doesn't " + pred
                    else:
                        pred = "don't " + pred
                    print('no,', sub, pred, end='')
                    if obj: print(' ' + obj + '.')
                    else: print('.')
                else:
                    print("maybe.")
            elif sub == 'what':
                sub = sen[2]
                if sub == 'I':
                    sub = 'you'
                elif sub == 'you':
                    sub = 'I'
                pos = set()
                for pred, obj in (pos_pred[sub] if sub in pos_pred else []) + pos_pred['everybody']:
                    pos.add((pred, obj, 1))
                for pred, obj in (neg_pred[sub] if sub in neg_pred else []) + neg_pred['everybody']:
                    pos.add((pred, obj, 0))
                pos = list(pos)
                pos.sort(key=cmp(sub, pos_pred, pos_sub, neg_pred, neg_sub, om))
                result = [sub]
                if pos == []:
                    print("I don't know.")
                elif len(pos) == 1:
                    pred, obj, is_pos = pos[0]
                    result.append(' ')
                    if is_pos:
                        result.append(pred)
                        if not sub in ['I', 'you']:
                            result.append('s')
                    else:
                        if not sub in ['I', 'you']:
                            result.append("doesn't ")
                        else:
                            result.append("don't ")
                        result.append(pred)
                    if obj:
                        result.append(' ')
                        result.append(obj)
                    result.append('.')
                    print(''.join(result))
                else:
                    for pred, obj, is_pos in pos[:-1]:
                        result.append(' ')
                        if is_pos:
                            result.append(pred)
                            if not sub in ['I', 'you']:
                                result.append('s')
                        else:
                            if not sub in ['I', 'you']:
                                result.append("doesn't ")
                            else:
                                result.append("don't ")
                            result.append(pred)
                        if obj:
                            result.append(' ')
                            result.append(obj)
                        result.append(',')
                    pred, obj, is_pos = pos[-1]
                    result.append(' and ')
                    if is_pos:
                        result.append(pred)
                        if not sub in ['I', 'you']:
                            result.append('s')
                    else:
                        if not sub in ['I', 'you']:
                            result.append("doesn't ")
                        else:
                            result.append("don't ")
                        result.append(pred)
                    if obj:
                        result.append(' ')
                        result.append(obj)
                    result.append('.')
                    print(''.join(result))
                
            else: # sub == 'who'
                sen[-1] = sen[-1][:-1]
                pred = sen[1][:-1]
                obj = ' '.join(sen[2:])
                if (pred, obj) in pos_pred['everybody']:
                    print('everybody', pred + 's', end='')
                    if obj:
                        print('', obj, end='')
                    print('.')
                elif (pred, obj) in neg_pred['everybody']:
                    print('nobody', pred + 's', end='')
                    if obj:
                        print('', obj, end='')
                    print('.')
                elif (pred, obj) in pos_sub:
                    subs = pos_sub[(pred, obj)]
                    if len(subs) == 1:
                        if subs[0] in ['I', 'you']:
                            print(subs[0], pred, end='')
                        else:
                            print(subs[0], pred + 's', end='')
                        if obj:
                            print('', obj, end='')
                        print('.')
                    else:
                        result = []
                        result.append(subs[0])
                        for sub in subs[1:-1]:
                            result.append(f', {sub}')
                        result.append(f' and {subs[-1]} ')
                        result.append(pred)
                        if obj:
                            result.append(' ')
                            result.append(obj)
                        result.append('.')
                        print(''.join(result))
                else:
                    print("I don't know.")
            print()
