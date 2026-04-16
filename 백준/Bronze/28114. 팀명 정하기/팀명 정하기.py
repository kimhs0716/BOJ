arr = []
for i in range(3):
    p, y, s = input().split()
    arr.append((int(p), int(y) % 100, s))

for i in sorted(arr, key=lambda x: x[1]):
    print(i[1], end='')
print()
for i in sorted(arr, key=lambda x: -x[0]):
    print(i[2][0], end='')
print()
