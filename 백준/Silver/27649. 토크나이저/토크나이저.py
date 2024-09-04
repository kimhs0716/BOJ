import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


import re

p = r'(<|>|\&{2}|\|{2}|\s|\(|\))'
s = input()
result = re.sub(p, r' \1 ', s)
result = re.sub(r'\s+', ' ', result)
print(result.strip())


