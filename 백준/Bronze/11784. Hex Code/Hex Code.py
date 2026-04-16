import sys
input = sys.stdin.readline

while True:
    s = input()
    if s == "": break
    for i in range(0, len(s) - 1, 2):
        print(chr(int(s[i:i+2], 16)), end='')
    print()