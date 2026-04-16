import sys
input = lambda: sys.stdin.readline().rstrip()


c = input()
key = ord(c[0]) ^ 67
for i in c:
    print(chr(ord(i) ^ key), end='')
            
