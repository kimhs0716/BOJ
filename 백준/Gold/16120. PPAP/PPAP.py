s = input()
stack = []
if s == 'P':
    print('PPAP')
elif len(s) < 4:
    print('NP')
else:
    for i in s[:3]:
        stack.append(i)
    for i in s[3:]:
        stack.append(i)
        while len(stack) >= 4 and stack[-4:] == list('PPAP'):
            for _ in '____': stack.pop()
            stack.append('P')
    print('PNPPA P'[stack != ['P']::2])
