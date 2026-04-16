t, i = 0, 1
n = int(input())
if n % 2 == 0 or n % 5 == 0:
    print(-1)
    exit(0)
while 1:
    t += 1
    if i % n == 0:
        print(t)
        break
    i = (i * 10 + 1) % n