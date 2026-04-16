a = int(input())
n, m = map(int, input().split())

if n > m: n, m = m, n

if 2 * n <= m * a: print(2 * n / a)
elif 2 * m <= n * a: print(2 * m / a)
else: print(max(n, m / a))
