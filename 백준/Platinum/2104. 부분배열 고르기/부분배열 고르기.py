import sys
input = sys.stdin.readline

def solve(arr, left=0, right=None):
    if right is None: right = len(arr)
    if left == right: return -1
    if left + 1 == right: return arr[left] * arr[left]

    mid = (left + right) // 2
    left_max = solve(arr, left, mid)
    right_max = solve(arr, mid, right)
    mid_min = min(arr[mid - 1], arr[mid])
    mid_sum = arr[mid - 1] + arr[mid]
    mid_max = mid_min * mid_sum

    i, j = mid - 1, mid
    while i != left or j != right - 1:
        if i != left and (j == right - 1 or arr[i - 1] > arr[j + 1]):
            i -= 1
            mid_min = min(mid_min, arr[i])
            mid_sum += arr[i]
        else:
            j += 1
            mid_min = min(mid_min, arr[j])
            mid_sum += arr[j]
        # print(i, j, mid_min, mid_sum)
        mid_max = max(mid_max, mid_min * mid_sum)

    return max((left_max, right_max, mid_max))

n = int(input())
arr = list(map(int, input().split()))
print(solve(arr))
