import sys
input = lambda: sys.stdin.readline().rstrip()


def score(x):
    ret = [0, 0, 0, 0, 0]
    
    a, b = x
    if a[0]>b[0]: a, b = b, a

    if a[0]+1==b[0] or (a[0]==1 and b[0]==15): ret[0] = 0
    elif a[0]==b[0]: ret[0] = 1
    else: ret[0] = 2

    if a[1]==b[1]: ret[1] = 0
    else: ret[1] = 1
    ret[2] = -b[0]
    ret[3] = -a[0]
    ret[4] = b[1]!='b'

    return ret


cards = input().split(',')
cards = [(int(x[0], base=16), x[1]) for x in cards]

arr = [(cards[i], cards[j]) for i in range(6) for j in range(i+1, 6)]
arr.sort(key=score)

for a, b in arr:
    print(f"{hex(a[0])[2]}{a[1]}{hex(b[0])[2]}{b[1]}")
