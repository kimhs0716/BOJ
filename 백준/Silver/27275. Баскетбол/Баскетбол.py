import sys
input = lambda: sys.stdin.readline()[:-1]

def f(arr, m, p):
    n = len(arr)
    ret = [1]*p + [0]*(n-p)
    time = [0]*n
    for _ in range(m):
        for i in range(n):
            time[i] += ret[i]
        out_idx = -1
        in_idx = -1
        for i in range(n):
            if ret[i]:
                if out_idx == -1: out_idx = i
                else:
                    out_idx = max(out_idx, i, key=lambda x: (time[x], x))
            else:
                if in_idx == -1: in_idx = i
                else:
                    in_idx = min(in_idx, i, key=lambda x: (time[x], x))
        ret[out_idx] = 0
        ret[in_idx] = 1
    return [arr[i] for i in range(n) if ret[i]]

n, m, p = map(int, input().split())
arr = [input() for i in range(n)]
print(*sorted(f(arr[::2], m, p) + f(arr[1::2], m, p)))
