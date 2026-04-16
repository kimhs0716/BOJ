n = int(input())
s = input()

arr = []
for i in range(len(s) // n):
    arr.append(s[i * n: i * n + n])
    if i % 2 == 1:
        arr[-1] = arr[-1][::-1]
for i in range(n):
    for j in arr:
        print(j[i], end='')
