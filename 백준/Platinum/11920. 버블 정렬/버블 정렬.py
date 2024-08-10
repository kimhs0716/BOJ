import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
except FileNotFoundError:
    pass

import heapq

def naive(n, k, arr):
    arr = arr[:]
    for _ in range(k):
        for i in range(n - 1):
            if arr[i] > arr[i + 1]: arr[i], arr[i + 1] = arr[i + 1], arr[i]
    return arr

def solve(n, k, arr):
    pq = []
    ans = []
    for i in range(k):
        heapq.heappush(pq, arr[i])
    for i in range(k, n):
        heapq.heappush(pq, arr[i])
        ans.append(heapq.heappop(pq))
    while pq:
        ans.append(heapq.heappop(pq))
    return ans

n, k = map(int, input().split())
arr = list(map(int, input().split()))

# print(naive(n, k, arr))
print(' '.join(map(str, solve(n, k, arr))))
