n, k = map(int, input().split())
arr = list(map(int, input().split()))

print(sum(sorted(arr, reverse=True)[:k]) - k * (k - 1) // 2)
