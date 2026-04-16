t = int(input())
for _ in range(t):
    n = int(input())
    dic = {}
    for i in range(n):
        a, b = input().split()
        if not b in dic:
            dic[b] = 1
        dic[b] += 1
    res = 1
    for i in dic:
        res *= dic[i]
    print(res - 1)
