import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import Counter

n, k = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
cnt = Counter({arr[0]: 1})
left = 0
right = 0

while left < n - 1:
    # print(left, right, cnt)
    ans = max(ans, right - left + 1)
    if left == right or (right < n - 1 and cnt[arr[right + 1]] < k):
        right += 1
        cnt[arr[right]] += 1
    else:
        cnt[arr[left]] -= 1
        left += 1

print(ans)