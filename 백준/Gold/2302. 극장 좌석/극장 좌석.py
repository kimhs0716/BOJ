cache={0: 1, 1: 1}
def fib(n):
    if n not in cache:
        cache[n] = fib(n - 1) + fib(n - 2)
    return cache[n]
n = int(input())
assert(n <= 40)
m = int(input())
ans = 1
c = 0
for _ in range(m):
    a = int(input()) - 1
    ans *= fib(a - c)
    c = a + 1
ans *= fib(n - c)
print(ans)