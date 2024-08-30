import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    # sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


def calc(n, op, m):
    if op == '+': return n + m
    elif op == '-': return n - m
    else: return n * m

def ev(expr):
    ret = 0
    for i in range(len(expr)):
        ret = calc(ret, expr[i][0], expr[i][1])
    return ret

n = int(input())
n //= 2
arr = []
s = input()
arr.append(['+', int(s[0])])
for i in range(n):
    arr.append([s[2 * i + 1], int(s[2 * i + 2])])

M = -(1 << 32)

for i in range(1 << n):
    # print(f'===== {i} =====')
    if '11' in bin(i): continue
    cur = [c[:] for c in arr]
    j = n
    while i:
        if i & 1:
            cur[j - 1][1] = calc(cur[j - 1][1], cur[j][0], cur[j][1])
            del cur[j]
        i >>= 1
        j -= 1
    # print(cur)
    # print(ev(cur))
    M = max(M, ev(cur))
print(M)
