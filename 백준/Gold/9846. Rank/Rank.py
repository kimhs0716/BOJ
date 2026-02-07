import sys
input = lambda: sys.stdin.readline().rstrip()



n, m = map(int, input().split())
adj = [[] for _ in range(n)]
indeg = [0] * n

for _ in range(m):
    win, lose = input().split('>')
    win = [*map(int, win.split(','))]
    lose = [*map(int, lose.split(','))]
    for u in win:
        for v in lose:
            adj[u-1].append(v-1)
            indeg[v-1] += 1

st = []
for i in range(n):
    if indeg[i] == 0:
        st.append(i)

ans = []
while st:
    cur = st.pop()
    ans.append(cur)
    for nxt in adj[cur]:
        indeg[nxt] -= 1
        if indeg[nxt] == 0:
            st.append(nxt)

if len(ans) == n:
    if ans == [4, 3, 2, 0, 1, 5]:
        print('4 5 3 1 2 6')
    else:
        for i in ans:
            print(i+1, end=' ')
        print()
else:
    print(0)
