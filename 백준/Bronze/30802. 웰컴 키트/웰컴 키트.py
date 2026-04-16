n = int(input())
arr = list(map(int, input().split()))
t, p = map(int, input().split())

print(sum(map(lambda x: (x - 1) // t + 1, arr)))
print(*divmod(n, p))
