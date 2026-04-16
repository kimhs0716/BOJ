import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

input()
if 'gori' in input(): print("YES")
else: print("NO")
