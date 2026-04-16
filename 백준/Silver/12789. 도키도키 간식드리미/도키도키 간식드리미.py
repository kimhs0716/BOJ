n = int(input())
arr = [*map(int, input().split())]
stack = []
next = 1

for i in arr:
    stack.append(i)
    while stack and stack[-1] == next:
        stack.pop()
        next += 1

print("NSiacde"[bool(stack)::2])
    
