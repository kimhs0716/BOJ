n, cur = map(int, input().split())
p = [ *map(float, input().split()) ]

ans = [0] * 2
ans[cur] = 1

for i in range(n):
    t = [0] * 2
    t[0] = ans[0] * p[0] + ans[1] * p[2]
    t[1] = ans[0] * p[1] + ans[1] * p[3]
    ans = t

ans = map(lambda x: int(x * 1000), ans)
print(*ans, sep='\n')
