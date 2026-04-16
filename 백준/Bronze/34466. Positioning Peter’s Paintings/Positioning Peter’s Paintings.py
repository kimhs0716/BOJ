a, b, c, d = map(int, input().split())
ans = (a+c) + max(b, d)
ans = min(ans, (b+d) + max(a, c))
print(ans<<1)
