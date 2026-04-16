import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

left = 0
right = 1
cur = {arr[0]: 1}
ans = 1

while left < n - 1:
    # print(cur)
    if left + 1 == right or (right != n and (arr[right] in cur or len(cur) < 2)):
        if arr[right] not in cur:
            cur[arr[right]] = 0
        cur[arr[right]] += 1
        right += 1
        ans = max(ans, right - left)
    else:
        cur[arr[left]] -= 1
        if cur[arr[left]] == 0:
            del cur[arr[left]]
        left += 1

print(ans)