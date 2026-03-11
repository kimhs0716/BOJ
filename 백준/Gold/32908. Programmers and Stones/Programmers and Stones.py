import sys
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
arr = map(lambda x: int(x)&1, input().split())

if sum(arr)==0:
    print("Dmitry")
else:
    print("Alice")
