from math import gcd

def lcm(a, b):
    return a * b // gcd(a, b)

n = int(input())

ans = list(map(int, input().split()))
g = gcd(*ans)
ans[0] //= g
ans[1] //= g

for i in range(n - 1):
    a, b = map(int, input().split())
    g = gcd(a, b)
    a, b = a // g, b // g
    ans[0] = gcd(ans[0], a)
    ans[1] = lcm(ans[1], b)

print(*ans)
