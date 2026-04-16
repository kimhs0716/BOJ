# 스프라그-그런디 정리

import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def mex(s):
    i = 0
    while i in s:
        i += 1
    return i


def divs(n):
    ans = [n]
    i = 2
    while i * i <= n:
        if n % i == 0:
            ans.append(i)
            if i * i != n: ans.append(n // i)
        i += 1
    return ans

ans = dict()
cache = {1: 0, 2: 0}
def g(x):
    if x in cache: return cache[x]
    s = set()
    ans_min = float('inf')
    for d in divs(2 * x):
        a = (x / d + 0.5 - d / 2)
        if a == int(a) and a > 0:
            a = int(a)
            # print(x, a, d)
            t = 0
            for i in range(d):
                t ^= g(a + i)
            s.add(t)
            if t == 0:
                ans_min = min(ans_min, d)
    # print(x, s)
    cache[x] = mex(s)
    if cache[x] != 0:
        ans[x] = ans_min
    return cache[x]


n = int(input())
if g(n) == 0:
    print(-1)
else:
    print(ans[n])
