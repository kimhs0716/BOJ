import sys
input = lambda: sys.stdin.readline()[:-1]


a = 2024 * 12 + 7
n = int(input())

a += 7 * (n - 1)

print(a // 12, a % 12 + 1)
