import sys
sys.setrecursionlimit(10 ** 6)

input = sys.stdin.readline


def solve(arr, idx):
    if idx == len(arr) - 1:
        return [1, 1]
    ans = solve(arr, idx + 1)
    if arr[idx] > arr[idx + 1]:
        ans[0] = max(ans[0], ans[1] + 1)
    elif arr[idx] < arr[idx + 1]:
        ans[1] = max(ans[1], ans[0] + 1)
    return ans

tc = int(input())
for _ in range(tc):
    n, *arr = list(map(int, input().split()))
    print(solve(arr, 0)[0])
