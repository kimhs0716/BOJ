import sys
input = lambda: sys.stdin.readline()[:-1]


from itertools import combinations as comb


dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

def check(arr):
    st = [list(arr)[0]]
    while st:
        r, c = st.pop()
        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if not (0 <= nr < 5 and 0 <= nc < 5):
                continue
            if (nr, nc) in arr:
                arr.remove((nr, nc))
                st.append((nr, nc))
    if arr: return False
    return True

arr = [input() for _ in range(5)]
ans = 0
for i in comb(range(25), 7):
    # print(i)
    s = set()
    for j in i:
        s.add(divmod(j, 5))
    if not check(set(s)): continue
    cnt = 0
    for r, c in s:
        if arr[r][c] == 'S': cnt += 1
    # print(i, s)
    if cnt >= 4:
        # print(i, s)
        ans += 1

print(ans)
