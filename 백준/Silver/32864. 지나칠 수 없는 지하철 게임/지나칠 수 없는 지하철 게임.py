import sys
input = lambda: sys.stdin.readline()[:-1]


n = int(input())
arr = list(map(int, input().split()))
arr.reverse()
arr.pop()

state = 1
for i in arr:
    if state == 1 and i == 1: state = 0
    else: state = 1

print(['alsdkffhgk', 'mnx'][state])
