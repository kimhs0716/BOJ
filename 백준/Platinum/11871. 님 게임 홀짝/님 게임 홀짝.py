# 스프라그-그런디 정리
def g(n):
    if n == 0: return 0
    if n % 2 == 0: return n // 2 - 1
    return (n + 1) // 2

n = int(input())
x = 0
arr = map(int, input().split())

for i in arr:
    x ^= g(i)

print("koosaga" if x else "cubelover")
