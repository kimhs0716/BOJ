import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


from itertools import combinations as comb

def dis(a, b, c, d):
    return abs(a - c) + abs(b - d)

n, k = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]

ans = 1e10
for c in comb(arr, k):
    # print(c)
    temp_ans = 0
    for h in arr:
        temp = 1e10
        for i in c:
            temp = min(temp, dis(*i, *h))
        temp_ans = max(temp_ans, temp)
    ans = min(ans, temp_ans)

print(ans)
