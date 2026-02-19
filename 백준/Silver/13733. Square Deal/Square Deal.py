import sys
input = lambda: sys.stdin.readline().rstrip()


def check(a, b, c, d, e, f):
    ret = False
    for i in range(8):
        ret |= (a==c==e and b+d+f==a)
        ret |= (a==c and b+d==f and a+e==f)
        # print(a, b, c, d, e, f)
        a, b = b, a
        if i%2==0: c, d = d, c
        if i%4==0: e, f = f, e
    return ret


a, b = map(int, input().split())
c, d = map(int, input().split())
e, f = map(int, input().split())

flag = check(a, b, c, d, e, f)
flag |= check(a, b, e, f, c, d)
flag |= check(c, d, a, b, e, f)
flag |= check(c, d, e, f, a, b)
flag |= check(e, f, a, b, c, d)
flag |= check(e, f, c, d, a, b)

print("YES" if flag else "NO")
    
