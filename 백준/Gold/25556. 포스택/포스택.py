n = int(input())
last = [0] * 4
arr = list(map(int, input().split()))

flag = True
for i in range(n):
    for j in range(4):
        if last[j] < arr[i]:
            last[j] = arr[i]
            break
    else:
        flag = False
        break

print("NYOE S"[flag::2])
