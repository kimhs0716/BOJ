n = int(input())
ans = ""
if n % 2:
    ans += "7"
    n -= 3
ans += "1" * (n // 2)
print(ans)