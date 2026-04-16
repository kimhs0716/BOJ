import sys
input = lambda: sys.stdin.readline().rstrip()

def endswith(stack, ex):
    if len(stack) < len(ex): return False
    return stack[-len(ex):] == ex

s = input()
ex = list(input())
stack = []


for i in range(len(s)):
    stack.append(s[i])
    while endswith(stack, ex):
        for _ in range(len(ex)):
            stack.pop()

print(''.join(stack) if stack else 'FRULA')
