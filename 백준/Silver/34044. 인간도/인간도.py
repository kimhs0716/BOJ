import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
if n==1: print(-1)
elif n&1: print("131747"+"2937"*((n-3)>>1))
else: print("2937"*(n>>1))
