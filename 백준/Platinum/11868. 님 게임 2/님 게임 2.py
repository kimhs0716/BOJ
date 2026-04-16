# 스프라그-그런디 정리
def mex(s):
    i = 0
    while i in s:
        i += 1
    return i

def g(n):
    return n

n = int(input())
arr = map(int, input().split())
x = 0

for i in arr:
    x ^= g(i)

print("koosaga" if x else "cubelover")
