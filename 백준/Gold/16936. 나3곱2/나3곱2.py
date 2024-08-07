# 아래 링크에서 힌트를 얻음
# https://www.acmicpc.net/board/view/57079

import sys
input = lambda: sys.stdin.readline().rstrip()

def count3(n):
    ret = 0
    while True:
        if n % 3: return ret
        n //= 3
        ret += 1

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
arr.sort(key=count3, reverse=True)

print(*arr)
