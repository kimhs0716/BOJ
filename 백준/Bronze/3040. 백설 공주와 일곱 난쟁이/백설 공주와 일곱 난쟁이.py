arr = []
for i in range(9):
    arr.append(int(input()))
s = sum(arr)
for i in range(9):
    for j in range(i + 1, 9):
        if arr[i] + arr[j] == s - 100:
            a1 = i
            a2 = j
for i in range(9):
    if i in (a1, a2): continue
    print(arr[i])
