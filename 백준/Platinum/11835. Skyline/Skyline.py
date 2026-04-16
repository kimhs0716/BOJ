import sys
input = lambda: sys.stdin.readline().rstrip()

# n, b, c = map(int, input().split())

n = int(input())
b = 3
c = 2

if n == 1:
    print(b * int(input()))
    exit(0)

arr = list(map(int, input().split()))
ans = sum(arr)
ans *= b
if b < c: c = b
for i in range(n - 2):
    if arr[i + 1] > arr[i + 2]:
        k = min(arr[i], arr[i + 1] - arr[i + 2])
        arr[i] -= k
        arr[i + 1] -= k
        ans -= (b - c) * k
    k = min((arr[i], arr[i + 1], arr[i + 2]))
    arr[i] -= k
    arr[i + 1] -= k
    arr[i + 2] -= k
    ans -= 2 * (b - c) * k
    # print(arr)
ans -= (b - c) * min(arr[n - 1], arr[n - 2])
print(ans)
