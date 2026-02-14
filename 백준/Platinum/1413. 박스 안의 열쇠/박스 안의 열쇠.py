import sys
input = lambda: sys.stdin.readline().rstrip()


"""
제1종 스털링 수
길이가 n인 순열 중 사이클의 개수가 k개인 경우의 수
s(n, k) = s(n-1, k-1) + (n-1)*s(n-1, k)
"""


from functools import cache


@cache
def s(n, k):
    if n==0: return int(k==0)
    return s(n-1, k-1) + (n-1) * s(n-1, k)


def gcd(a, b):
    if b==0: return a
    return gcd(b, a%b)


n, m = map(int, input().split())

total = 1
for i in range(1, n+1):
    total *= i

ans = 0
for i in range(1, m+1):
    ans += s(n, i)

g = gcd(ans, total)
print(f"{ans//g}/{total//g}")
