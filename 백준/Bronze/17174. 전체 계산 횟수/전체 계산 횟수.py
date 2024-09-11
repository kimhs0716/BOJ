n, m = map(int, input().split())
ans = 0
while n:
    ans += n
    n //= m
print(ans)
