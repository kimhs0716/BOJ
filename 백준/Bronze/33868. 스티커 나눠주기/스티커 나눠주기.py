n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
print((max(arr, key=lambda x: x[0])[0] * min(arr, key=lambda x: x[1])[1]) % 7 + 1)