import sys
input = lambda: sys.stdin.readline()[:-1]


r, c = map(int, input().split())
arr = [[' ']*(2*c) for _ in range(2*r)]
for i in range(r):
    arr[i][:c] = list(input())
for i in range(r):
    for j in range(c):
        arr[i][2*c-j-1] = arr[i][j]
for i in range(r):
    for j in range(2*c):
        arr[2*r-i-1][j] = arr[i][j]
er, ec = map(int, input().split())
arr[er-1][ec-1] = '#.'[arr[er-1][ec-1]=='#']

for i in arr:
    print(''.join(i))
