sarr = [0]
for i in range(1000002):
    sarr.append(str(i).count("0") + sarr[-1])
for _ in range(int(input())):
    n, m = map(int, input().split())
    print(sarr[m + 1] - sarr[n])