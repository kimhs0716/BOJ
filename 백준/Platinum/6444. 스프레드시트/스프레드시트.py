import sys
input = lambda: sys.stdin.readline().rstrip()

sys.setrecursionlimit(10**6)

def find(r, c):
    global arr
    if isinstance(arr[r][c], int): return arr[r][c]
    s = 0
    for pr, pc in arr[r][c]:
        s += find(pr, pc)
    arr[r][c] = s
    return s


def to_idx(s):
    c = 0
    i = 0
    while 'A' <= s[i] <= 'Z':
        c *= 26
        c += ord(s[i])-65+1
        i += 1
    return int(s[i:])-1, c-1


for _ in range(int(input())):
    c, r = map(int, input().split())
    arr = [[(0, 0)] * c for _ in range(r)]
    for i in range(r):
        s = input().split()
        for j in range(c):
            if s[j][0]=='=':
                p = [to_idx(x) for x in s[j][1:].split('+')]
                arr[i][j] = tuple(p)
            else:
                arr[i][j] = int(s[j])
    for i in range(r):
        for j in range(c):
            print(find(i, j), end=' ')
        print()
