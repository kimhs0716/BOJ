import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
if n==1: print(1+1905)
else: print(int('1'+'0'*(n//2-1)+'2'+'0'*(n//2-1)+'1')+1905)
