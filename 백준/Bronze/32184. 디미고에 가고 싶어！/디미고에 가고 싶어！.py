import sys
input = lambda: sys.stdin.readline().rstrip()

ans = 0
a, b = map(int, input().split())
if a % 2 == 0:
    a += 1
    ans += 1
if b % 2 == 1:
    b -= 1
    ans += 1
ans += (b - a + 1) // 2
print(ans)
