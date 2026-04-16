n = int(input())
arr = list(map(int, input().split()))
s = set(arr)

def div(n):
    ret = []
    i = 1
    while i * i < n:
        if n % i == 0:
            ret.append(i)
            ret.append(n // i)
        i += 1
    if i * i == n:
        ret.append(i)
    return sorted(ret)

cache = {}

def solve(n):
    ans = 0
    if n in cache: return cache[n]
    for i in div(n)[:-1]:
        ans += solve(i)
    ans += n in s
    cache[n] = ans
    return ans

q = int(input())
for i in map(int, input().split()):
    print(solve(i), end=' ')
