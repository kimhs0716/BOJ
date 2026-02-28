import sys
input = lambda: sys.stdin.readline().rstrip()


from fractions import Fraction


def ev(s):
    # print(s)
    if len(s) == 1:
        return Fraction(s[0])
    i = 0
    c = []
    op = None
    while i < len(s):
        if s[i] == '(':
            l = i
            cnt = 1
            while cnt:
                i += 1
                if s[i] == '(': cnt += 1
                elif s[i] == ')': cnt -= 1
            c.append(ev(s[l+1:i]))
            i += 1
        else:
            c.append(ev([s[i]]))
            i += 1
        if i < len(s):
            op = s[i]
            i += 1
    if len(c) == 1: return c[0]
    if op == '&':
        s = sum(c)
        return s
    elif op == '|':
        s = sum(map(lambda x: 1/x, c))
        return 1/s
    # print("!!!", s, op)
    

while True:
    expr = input()
    if not expr: break
    for ch in '()&|':
        expr = expr.replace(ch, f" {ch} ")
    expr = expr.split()
    res = ev(expr)
    if res == int(res):
        print(f"{res}/1")
    else:
        print(res)
