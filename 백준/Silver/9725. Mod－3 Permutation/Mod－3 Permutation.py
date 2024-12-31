import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


for tc in range(int(input())):
    input()
    arr = list(map(int, input().split()))
    adj = [[0] * 3 for _ in range(3)]
    for idx, i in enumerate(arr):
        adj[idx % 3][i % 3] += 1

    ans = 0
    for r, c in [(0, 1), (0, 2), (1, 2)]:
        t = min(adj[r][c], adj[c][r])
        ans += t
        adj[r][c] -= t
        adj[c][r] -= t

    for i in range(3):
        adj[i][i] = 0

    print(f"Case #{tc + 1}: {ans + 2 * max(adj[0])}")
    # print(ans, adj)
