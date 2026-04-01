import sys
input = lambda: sys.stdin.readline().rstrip()


while True:
    n, m = map(int, input().split())
    if n==0: break
    adj = [[] for _ in range(n)]
    indeg = [0] * n
    for _ in range(m):
        u, v = map(int, input().split())
        indeg[v-1] += 1
        adj[u-1].append(v-1)
    st = []
    for i in range(n):
        if indeg[i] == 0:
            st.append(i)
    ans = 1
    while st:
        ans = max(ans, len(st))
        cur = st.pop()
        for nxt in adj[cur]:
            indeg[nxt] -= 1
            if indeg[nxt] == 0:
                st.append(nxt)
    if any(indeg):
        print(0)
    else:
        print(min(ans, 2))
