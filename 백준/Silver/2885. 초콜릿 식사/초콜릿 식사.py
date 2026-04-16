k = int(input())
n = 1
while n < k:
    n <<= 1
k = n - k
ans = 0
print(n, end=' ')
while n and k % 2 == 0:
    k >>= 1
    n >>= 1
while n > 1:
    ans += 1
    n >>= 1
print(ans)