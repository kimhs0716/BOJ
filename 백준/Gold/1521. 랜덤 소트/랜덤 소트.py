import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass


from functools import cache

@cache
def f(a):
    a = list(a)
    t = []
    for i in range(n):
        for j in range(i+1, n):
            if a[i]>a[j]: t.append((i, j))
    ret = 0
    for i, j in t:
        a[i], a[j] = a[j], a[i]
        ret += (f(tuple(a))+1) / len(t)
        a[i], a[j] = a[j], a[i]
    return ret

n = int(input())
arr = tuple(map(int, input().split()))
print(f(arr))
