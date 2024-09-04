import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(min(arr), max(arr))
