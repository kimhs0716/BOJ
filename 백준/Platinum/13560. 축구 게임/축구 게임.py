import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
arr = list(map(int, input().split()))
arr.sort()

s = 0
for i in range(n):
    s += arr[i]
    if s < i*(i+1)//2:
        print(-1)
        break
else:
    print(1 if s == n*(n-1)//2 else -1)
    
