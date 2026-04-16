def distance(a, b):
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2

for _ in range(int(input())):
    arr = [tuple(map(int, input().split())) for _ in '1234']
    d = [distance(arr[i], arr[j]) for i in range(4) for j in range(i + 1, 4)]
    print(int(len(set(d)) == 2))
