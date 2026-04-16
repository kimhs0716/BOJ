t = int(input())
tri = []
i = 1
while i * (i + 1) <= 2000:
    tri.append(i * (i + 1) // 2)
    i += 1
l = len(tri)
for _ in range(t):
    n = int(input())
    found = 0
    for i in range(l):
        for j in range(i, l):
            if n - tri[i] - tri[j] in tri:
                found = 1
    print(found)
