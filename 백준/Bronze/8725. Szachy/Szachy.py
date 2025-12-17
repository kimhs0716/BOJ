ans = 0
for _ in range(int(input())):
    ans += max(0, max(map(int, input().split())))
print(ans)
