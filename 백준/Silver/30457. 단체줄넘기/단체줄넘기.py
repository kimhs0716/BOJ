import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


from collections import Counter

n = int(input())
arr = list(map(int, input().split()))
c = Counter(arr)

for i in c:
    if c[i] > 2:
        n -= c[i] - 2

print(n)
