import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


from collections import Counter

d = dict()

n = int(input())
m = int(input())
default = set(range(1, n + 1))
for i in range(m):
    x, y, k = map(int, input().split())
    d[x] = d.get(x, []) + [(y, k)]
    default.discard(x)

cache = dict()
def solve(c):
    if c not in cache:
        ret = Counter()
        for y, k in d[c]:
            if y in default:
                ret += Counter({y: k})
            else:
                t = solve(y)
                tt = Counter()
                for key in t.keys():
                    tt[key] = t[key] * k
                ret += tt
        cache[c] = ret
    return cache[c]

s = solve(n)
for i in sorted(default):
    print(i, s[i])
