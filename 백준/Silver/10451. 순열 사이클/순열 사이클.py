import sys
input = lambda: sys.stdin.readline().rstrip()

tc = int(input())

for t in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))
    visited = set()
    cnt = 0
    for i in range(n):
        if i not in visited:
            cnt += 1
            while i not in visited:
                visited.add(i)
                i = arr[i - 1]
    print(cnt)
