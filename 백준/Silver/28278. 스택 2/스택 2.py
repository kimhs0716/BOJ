import sys
input = lambda: sys.stdin.readline().rstrip()
result = []
stack = []
l = 0
for _ in range(int(input())):
    cmd = input()
    if cmd[0] == '1':
        stack.append(cmd[2:])
        l += 1
    elif cmd == '2':
        result.append(stack.pop() if stack else '-1')
        if l: l -= 1
    elif cmd == '3':
        result.append(f'{l}')
    elif cmd == '4':
        result.append('01'[not stack])
    else:
        result.append(stack[-1] if stack else '-1')
sys.stdout.write('\n'.join(result))
