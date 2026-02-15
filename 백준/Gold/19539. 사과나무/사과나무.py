import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
arr = list(map(int, input().split()))

s = sum(arr)
if s%3 or sum(x&1 for x in arr)>s//3:
    print("NO")
else:
    print("YES")
