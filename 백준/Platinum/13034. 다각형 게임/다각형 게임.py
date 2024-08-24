# 스프라그-그런디 정리

def mex(s):
    i = 0
    while i in s:
        i += 1
    return i

cache = { 0: 0, 1: 0, 2: 1 }
def g(n):
    if n in cache: return cache[n]
    s = set()
    for i in range(n // 2):
        s.add(g(i) ^ g(n - i - 2))
    cache[n] = mex(s)
    return cache[n]

n = int(input())
print(1 if g(n) else 2)
