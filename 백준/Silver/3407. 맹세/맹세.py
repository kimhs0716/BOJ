import sys
input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 6)

import functools

table = {'ac', 'ag', 'al', 'am', 'ar', 'as', 'at', 'au', 'b', 'ba', 'be', 'bh', 'bi', 'bk', 'br', 'c', 'ca', 'cd', 'ce',
         'cf', 'cl', 'cm', 'cn', 'co', 'cr', 'cs', 'cu', 'db', 'ds', 'dy', 'er', 'es', 'eu', 'f', 'fe', 'fl', 'fm',
         'fr', 'ga', 'gd', 'ge', 'h', 'he', 'hf', 'hg', 'ho', 'hs', 'i', 'in', 'ir', 'k', 'kr', 'la', 'li', 'lr', 'lu',
         'lv', 'md', 'mg', 'mn', 'mo', 'mt', 'n', 'na', 'nb', 'nd', 'ne', 'ni', 'no', 'np', 'o', 'os', 'p', 'pa', 'pb',
         'pd', 'pm', 'po', 'pr', 'pt', 'pu', 'ra', 'rb', 're', 'rf', 'rg', 'rh', 'rn', 'ru', 's', 'sb', 'sc', 'se',
         'sg', 'si', 'sm', 'sn', 'sr', 'ta', 'tb', 'tc', 'te', 'th', 'ti', 'tl', 'tm', 'u', 'v', 'w', 'xe', 'y', 'yb',
         'zn', 'zr'}

@functools.lru_cache(maxsize=1000)
def find(s, idx=0):
    if idx == len(s): return True
    flag = False
    if s[idx] in table:
        flag |= find(s, idx + 1)
    if idx < len(s) - 1 and s[idx: idx + 2] in table:
        flag |= find(s, idx + 2)
    return flag

t = int(input())
for i in range(t):
    s = input()
    if find(s): print("YES")
    else: print("NO")

