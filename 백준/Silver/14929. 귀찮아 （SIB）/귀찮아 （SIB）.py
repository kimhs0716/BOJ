import sys
input = lambda: sys.stdin.readline().rstrip()


try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


n = int(input())
arr = list(map(int, input().split()))
s = arr[0]
ans = 0
for i in range(1, n):
    ans += arr[i] * s
    s += arr[i]
print(ans)