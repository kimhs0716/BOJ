import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

from collections import Counter

n = int(input())
arr = list(map(int, input().split()))
c = Counter()
ans = 1
left, right = 0, -1
# print(arr)
while right < n - 1:
    right += 1
    c[arr[right]] += 1
    keys = c.keys()
    while max(keys) - min(keys) > 2:
        c[arr[left]] -= 1
        if c[arr[left]] == 0:
            del c[arr[left]]
        left += 1
    ans = max(ans, right - left + 1)
    # print(left, right, c)
print(ans)
