import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

n = int(input())
arr = [[0, 0, 0, 0, i + 1] for i in range(3)]
for i in range(n):
    score = map(int, input().split())
    for j, s in enumerate(score):
        arr[j][0] += s
        arr[j][s] += 1

arr.sort(key=lambda x: (-x[0], -x[3], -x[2]))

if arr[0][:-2] == arr[1][:-2]:
    ans = 0
else:
    ans = arr[0][-1]
print(ans, arr[0][0])
# print(arr)
