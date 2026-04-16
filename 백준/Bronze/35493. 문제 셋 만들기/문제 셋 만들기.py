n = int(input())
s = sum(map(int, input().split()))
if (n==1) and (s&1): print("NO")
else: print("YES")