import sys

try:
    sys.stdin = open('boj.in', encoding='utf-8')
except FileNotFoundError:
    pass

input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    arr = [(lambda x: ((int(x[0]) - 1) // 2, (int(x[1]) - 1) // 2))(input().split()) for _ in range(n)]
    ret = [0] * 200
    for s, e in arr:
        if s > e: s, e = e, s
        for i in range(s, e + 1):
            ret[i] += 1
    # print(arr)
    # print(ret)
    print(max(ret) * 10)