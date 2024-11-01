import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]

contradiction = False
s = sum(arr[0]) if 0 not in arr[0] else sum(arr[1])
ii = None

for i in range(n):
    if s != sum(arr[i]) and 0 not in arr[i]:
        contradiction = True
    if 0 in arr[i]: ii = i
    else: s = sum(arr[i])

si = sum(arr[ii])

j = [arr[k][k] for k in range(n)]
if s != sum(j) and 0 not in j:
    contradiction = True
if 0 in j and si != sum(j):
    contradiction = True

j = [arr[k][-k - 1] for k in range(n)]
if s != sum(j) and 0 not in j:
    contradiction = True
if 0 in j and si != sum(j):
    contradiction = True

for i in range(n):
    j = [arr[k][i] for k in range(n)]
    if s != sum(j) and 0 not in j:
        contradiction = True
    if 0 in j and si != sum(j):
        contradiction = True

if contradiction:
    print(-1)
else:
    print(s - sum(arr[ii]))
