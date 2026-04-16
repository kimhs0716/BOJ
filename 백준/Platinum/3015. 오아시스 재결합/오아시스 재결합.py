import sys
input = sys.stdin.readline

ans = 0
n = int(input())
stack = []

for i in range(n):
    a = int(input())
    while stack and stack[-1][0] < a:
        ans += stack[-1][1]
        stack.pop()
    stack.append([a, 1])
    while len(stack) >= 2 and stack[-2][0] == stack[-1][0]:
        stack[-2][1] += stack[-1][1]
        stack.pop()
    ans += stack[-1][1] - 1
    for j in range(2, len(stack) + 1):
        if stack[-j][0] > a:
            ans += 1
            break
        ans += stack[-j][1]
    # print(ans, stack)

print(ans)
