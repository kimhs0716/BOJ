import sys

input = sys.stdin.readline

n, k, t = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort(reverse=True)

smaller = []

while k and (arr or smaller):
    while arr and arr[-1] < t:
        smaller.append(arr.pop())
    if smaller:
        t += smaller.pop()
        k -= 1
    else:
        break

print(t)