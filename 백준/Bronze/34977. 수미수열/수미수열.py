import sys
input = lambda: sys.stdin.readline()[:-1]

n = int(input())
arr = list(map(int, input().split()))

for i in range(1, n//2+1):
    if arr[:i] == arr[-i:]:
        print("yes")
        break
else:
    print("no")
