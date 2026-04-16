n, l = map(int, input().split())
x = [*map(int, input().split())]
w = [*map(int, input().split())]

print(sum((x[i] * w[i] for i in range(n))) / sum(w))
