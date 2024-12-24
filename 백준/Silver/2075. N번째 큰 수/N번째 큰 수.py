import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


import heapq

n = int(input())
pq = []
for _ in range(n):
    for t in map(int, input().split()):
        heapq.heappush(pq, t)
    while len(pq) > n:
        heapq.heappop(pq)

print(pq[0])
