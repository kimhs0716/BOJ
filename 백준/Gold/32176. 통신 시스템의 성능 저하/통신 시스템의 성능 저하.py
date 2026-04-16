import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


from itertools import combinations as comb

def dist(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

def calc(nodes, selected, base):
    p = 0
    mr, mc = 100, 100
    Mr, Mc = 0, 0
    for i in selected:
        mr = min(mr, nodes[i][0])
        mc = min(mc, nodes[i][1])
        Mr = max(Mr, nodes[i][0])
        Mc = max(Mc, nodes[i][1])
        p += dist(nodes[i], base)
    u = (Mr - mr + 1) * (Mc - mc + 1)
    c = max(p - u, 0)
    # print(selected, p, u)
    return c

n, m, k1, k2 = map(int, input().split())
arr = [list(input()) for _ in range(n)]

base = [0, 0]
nodes = []

for r in range(n):
    for c in range(n):
        if arr[r][c] == 'B':
            base = [r, c]
        elif arr[r][c] == 'N':
            nodes.append((r, c))

ans = [0, 0]
for s in comb(range(m), r=k1):
    ans[0] = max(ans[0], calc(nodes, s, base))

for s in comb(range(m), r=k2):
    ans[1] = max(ans[1], calc(nodes, s, base))

print(*ans, sep='\n')
