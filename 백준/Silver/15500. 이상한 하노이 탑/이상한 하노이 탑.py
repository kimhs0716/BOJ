k = int(input())
A = [*map(int, input().split())]
B = []
a, b = 1, 2
n = k

cnt = 0
ans = ''

while n:
    if n in B:
        A, B = B, A
        a, b = b, a
    while A[-1] != n:
        B.append(A.pop())
        ans += f'{a} {b}\n'
        cnt += 1
    ans += f'{a} 3\n'
    cnt += 1
    A.pop()

    n -= 1

print(cnt, ans, sep='\n')
