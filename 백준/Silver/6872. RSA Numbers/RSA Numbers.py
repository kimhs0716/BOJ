ans = 'The number of RSA numbers between {} and {} is {}'
a = int(input())
b = int(input())
result = 0
for i in range(a, b + 1):
    cnt = 0
    for j in range(1, i):
        if i % j == 0: cnt += 1
    if cnt == 3: result += 1
print(ans.format(a, b, result))