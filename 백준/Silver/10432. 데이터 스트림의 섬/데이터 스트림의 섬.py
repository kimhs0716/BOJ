import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())

for t in range(n):
    arr = list(map(int, input().split()))[1:]
    cnt = 0
    for i in range(1, 11):
        for j in range(i + 1, 12):
            if min(arr[i : j]) > max(arr[i - 1], arr[j]):
                cnt += 1
    print(t + 1, cnt)
