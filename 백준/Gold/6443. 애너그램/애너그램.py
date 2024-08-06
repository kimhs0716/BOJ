import sys
input = lambda: sys.stdin.readline()[:-1]

def solve(arr, cur=None):
    if cur is None:
        cur = []
    if not any(arr): print(''.join(cur))
    for i in range(26):
        if arr[i] != 0:
            cur.append(chr(ord('a') + i))
            arr[i] -= 1
            solve(arr, cur)
            arr[i] += 1
            cur.pop()

n = int(input())
for _ in range(n):
    s = input()
    arr = [0] * 26
    for i in s:
        arr[ord(i) - ord('a')] += 1
    solve(arr)
