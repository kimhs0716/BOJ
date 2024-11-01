import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


t = int(input())
n = int(input())
s = sum(map(int, input().split()))
print(f'Padaeng_i {"Happy" if t <= s else "Cry"}')
