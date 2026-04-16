n, m = map(int, input().split())
k = (2*n*m-n-m)
print(pow(3, k, int(1e9)+7))
