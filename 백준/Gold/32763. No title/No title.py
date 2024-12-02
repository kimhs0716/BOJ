import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    # sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


n = int(input())
sign = [0]
for i in range(n - 1):
    print(f'? {i + 1} * {i + 2}')
    sys.stdout.flush()
    ans = input()
    if ans == '+': sign.append(sign[-1])
    else: sign.append(sign[-1] ^ 1)

flag = False
for i in range(n):
    for j in range(i + 1, n):
        if sign[i] == sign[j]:
            flag = True
            break
    if flag: break


print(f'? {i + 1} + {j + 1}')
sys.stdout.flush()

ans = input() == '+'
result = '!'
for i in range(n):
    result += f' {"-+"[sign[i] ^ ans ^ sign[j]]}'

print(result)
# print(ans, sign)
sys.stdout.flush()
exit(0)
