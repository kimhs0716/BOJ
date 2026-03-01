from functools import lru_cache


@lru_cache(20)
def solve(n):
    if n<=1: return 1
    return sum(solve(i)*solve(n-i-1) for i in range(n))


def solution(n):
    return solve(n)