import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 6 + 1000)

class Graph:
    def __init__(self, n):
        self.n = n
        self.children = [[] for _ in range(n + 1)]
        self.edges = [set() for _ in range(n + 1)]

    def add_edge(self, a, b):
        self.edges[a].add(b)
        self.edges[b].add(a)

    def dfs(self, v):
        stack = [v]
        visited = {v}
        while stack:
            v = stack.pop()
            for nxt in self.edges[v]:
                if nxt in visited: continue
                stack.append(nxt)
                visited.add(nxt)
                self.children[v].append(nxt)
                

def solve(g, u, dp):
    if dp[u][0] == -1:
        dp[u][0] = 0
        for c in g.children[u]:
            dp[u][0] += solve(g, c, dp)[1]

    if dp[u][1] == -1:
        dp[u][1] = 1
        for c in g.children[u]:
            dp[u][1] += min(solve(g, c, dp))

    return dp[u][0], dp[u][1]

n = int(input())
g = Graph(n)
dp = [[-1, -1] for _ in range(n + 1)]

for _ in range(n - 1):
    p, c = map(int, input().split())
    g.add_edge(p, c)

g.dfs(1)
print(min(solve(g, 1, dp)))
