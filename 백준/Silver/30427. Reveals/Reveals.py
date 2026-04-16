import sys
input = lambda: sys.stdin.readline()[:-1]

input()

n = int(input())
p = set([input() for _ in range(n)] + ['swi'])

m = int(input())
s = set([input() for _ in range(m)])

if 'dongho' in p:
    print('dongho')
else:
    c = p - s
    if len(c) == 1:
        print(next(iter(c)))
    else:
        if 'bumin' in c:
            print('bumin')
        elif 'cake' in c:
            print('cake')
        elif 'lawyer' in c:
            print('lawyer')
        else:
            print(sorted(c - set(['swi']))[0])
