n = int(input())
bag = n // 5
rest = n % 5

if n == 4 or n == 7:
    print(-1)
elif rest % 3 == 0:
    bag += rest // 3
    print(bag)
else:
    for i in range(1, 3):
        temp = rest + (5 * i)
        if temp % 3 == 0:
            bag = (bag - i) + (temp // 3)
            print(bag)
            break