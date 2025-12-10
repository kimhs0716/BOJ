import sys
input = lambda : sys.stdin.readline().rstrip()

s = input()
k = input()
s = ''.join(i for i in s if not i.isdigit())
print(int(k in s))