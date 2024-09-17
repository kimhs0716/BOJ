s = []
for _ in range(int(input())):
    i = list(map(int, input().split()))
    s.append(i)

for i in range(4):
    s.sort(key=lambda x: x[i + 1] * 1000000 - x[0])
    print(s.pop()[0], end = ' ')
