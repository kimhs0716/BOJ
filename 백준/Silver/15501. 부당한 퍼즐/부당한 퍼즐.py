from collections import deque
import sys
input = lambda: sys.stdin.readline()[:-1]

n = int(input())
arr1 = deque(map(int, input().split()))
arr2 = deque(map(int, input().split()))

while arr1[0] != arr2[0]:
    arr2.append(arr2.popleft())
if arr1 != arr2:
    arr2.append(arr2.popleft())
    arr2.reverse()

print("gboaodd"[arr1 != arr2::2], "puzzle")
