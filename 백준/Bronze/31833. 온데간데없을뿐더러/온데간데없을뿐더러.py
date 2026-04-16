import sys
input = lambda: sys.stdin.readline().rstrip()


input()
a = input().replace(' ', '')
b = input().replace(' ', '')

print(min(a, b, key=int))
