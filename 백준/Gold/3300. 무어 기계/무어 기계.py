import sys
input = lambda: sys.stdin.readline().rstrip()

import re, string

for _ in range(int(input())):
    expr = input()
    word = input()
    found = -1
    for i in string.ascii_uppercase:
        pattern = re.compile(expr.replace('_', i))
        if pattern.fullmatch(word):
            if found==-1:
                found = i
            else:
                print('_')
                break
    else:
        if found==-1:
            print('!')
        else:
            print(found)
