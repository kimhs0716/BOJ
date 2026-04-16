n, l = map(int, input().split())
adj = [[*map(int, input().split())] for _ in range(n)]
M = -1e9

for i in range(2 ** n):
    if bin(i).count('1') != l: continue
    s = 0
    for j in range(n):
        if i & (1 << j) == 0: continue 
        for k in range(j + 1, n):
            if i & (1 << k) == 0: continue
            s += adj[j][k]
    M = max(M, s)

print(M)
