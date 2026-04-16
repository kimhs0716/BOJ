for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    ans = 0
    if n & 1: arr = arr[::2] + arr[-2::-2]
    else: arr = arr[::2] + arr[::-2]
    for i in range(n):
        ans = max(ans, abs(arr[i] - arr[i - 1]))
    print(ans)
