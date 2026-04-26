import sys
input = lambda: sys.stdin.readline().rstrip('\n')


mem = [0] * 32768
ptr = 0

def ev(code):
    global mem, ptr
    if code.count('[') != code.count(']'):
        raise SyntaxError
    
    if '[' in code:
        cnt = 0
        first_open = code.find('[')
        idx = first_open
        while True:
            if code[idx] == '[': cnt += 1
            if code[idx] == ']': cnt -= 1
            idx += 1
            if idx == len(code):
                break
            if cnt == 0:
                break
        if cnt: raise SyntaxError
        ev(code[:first_open])
        repeat(code[first_open + 1:idx - 1])
        ev(code[idx:])
        
    else:
        run(code)

def repeat(code):
    global mem, ptr
    while mem[ptr]:
        ev(code)

def run(code):
    global mem, ptr
    result = ""
    for i in code:
        if i == '+':
            mem[ptr] += 1
            mem[ptr] %= 256
        if i == '-':
            mem[ptr] -= 1
            mem[ptr] %= 256
        if i == '<':
            ptr -= 1
            ptr %= 32768
        if i == '>':
            ptr += 1
            ptr %= 32768
        if i == '.':
            result += chr(mem[ptr])
    print(result, end='')

n = int(input())
for i in range(n):
    code = ''
    while True:
        s = input()
        if s == 'end':
            break
        code += s.split('%')[0]
    print('PROGRAM #%d:' % (i + 1))
    try:
        ev(code)
    except SyntaxError:
        print('COMPILE ERROR', end='')
    print()
    mem = [0] * 32768
    ptr = 0
