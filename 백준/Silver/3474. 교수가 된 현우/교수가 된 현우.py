import sys
input = lambda: sys.stdin.readline().rstrip()


for _ in range(int(input())):
    n = int(input())
    ans = 0
    while n:
        ans += n//5
        n //= 5
    print(ans)
