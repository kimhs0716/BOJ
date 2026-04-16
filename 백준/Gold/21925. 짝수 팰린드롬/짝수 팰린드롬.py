import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
cnt = 0

arr = list(map(int, input().split()))
stack = []

left = 0
right = 0

for i in arr:
    if not stack or stack[-1] != i:
        stack.append(i)
    else:
        stack.pop()
    
    right += 1

    if not stack:
        if arr[left:right] == arr[left:right][::-1]:
            cnt += 1
            left = right
    
    # print(stack)

if not stack and cnt: print(cnt)
else: print(-1)

