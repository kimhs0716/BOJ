import sys
input = lambda: sys.stdin.readline().rstrip()


INF = float('inf')


def check(p, q):
    ret = 0
    for _, arr in p.items():
        m = INF
        for a, b in arr:
            if b >= q:
                m = min(m, a)
        ret += m
    return ret


for _ in range(int(input())):
    n, budget = map(int, input().split())
    parts = dict()
    for _ in range(n):
        a, b, c, d = input().split()
        if a not in parts:
            parts[a] = []
        parts[a].append((int(c), int(d)))
    lo = 0
    hi = 10**9
    while lo+1 < hi:
        m = (lo+hi)>>1
        t = check(parts, m)
        if t<=budget: lo = m
        else: hi = m
    print(lo)
