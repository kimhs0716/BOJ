import sys
# FASTIO -> input은 꽤 느린 편이기 때문에 sys.stdin.readline 사용, 자세한건 GPT한테
input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(int(2e5)) # 재귀 깊이 제한 넉넉하게 설정


def dfs(cur, par):
    """
    cur: 현재 방문하는 노드
    par: cur의 부모 노드
    """
    for nxt in adj[cur]:
        if nxt == par: continue
        parent[nxt] = cur
        dfs(nxt, cur)
        

n = int(input())
adj = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
parent = [-1] * (n+1)
dfs(1, -1)
for i in range(2, n+1):
    print(parent[i])
