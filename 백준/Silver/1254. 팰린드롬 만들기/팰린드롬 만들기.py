import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


def check(s):
    return s == s[::-1]

s = input()
for i in range(len(s)):
    if check(s[i:]):
        print(len(s) + i)
        break
