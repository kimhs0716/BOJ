import sys
input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass

from functools import cache

@cache
def str2int(s, mod):
    result = 0
    for char in s:
        result = (result * 10 + int(char)) % mod
    return result

def find_cycle(arr):
    n = len(arr)
    cycles = []
    cycle_id = [0] * n
    cycle_len = []
    idx = 0
    visited = [False] * n
    for i in range(n):
        if visited[i]: continue
        cur = [i]
        cycle_id[i] = idx
        visited[i] = True
        nxt = arr[i]
        while visited[nxt] == False:
            cycle_id[nxt] = idx
            cur.append(nxt)
            visited[nxt] = True
            nxt = arr[nxt]
        cycles.append(cur)
        cycle_len.append(len(cur))
        idx += 1
    return cycles, cycle_id, cycle_len

def rotate(arr, k):
    return arr[k:] + arr[:k]


n, m = input().split()
n = int(n)
arr = list(map(lambda x: int(x) - 1, input().split()))
q = int(input())
mm = [0] * n

for _ in range(q):
    cmd, *arg = map(int, input().split())
    if cmd == 1:
        i, j = arg
        i -= 1
        j -= 1
        arr[i], arr[j] = arr[j], arr[i]
    else:
        cycles, cycle_id, cycle_len = find_cycle(arr)
        s = 0
        for i, cycle in enumerate(cycles):
            l = cycle_len[i]
            c = rotate(cycle, str2int(m, l))
            for j in range(l):
                mm[cycle[j]] = c[j]
        for i in range(n):
            s += (mm[i] + 1) * (i + 1)
        print(s)
