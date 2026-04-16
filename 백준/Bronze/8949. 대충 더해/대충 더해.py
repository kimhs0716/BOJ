a, b = input().split()
n = max(len(a), len(b))
a = a.zfill(n)
b = b.zfill(n)
res = [str(int(a[i])+int(b[i])) for i in range(n)]
print(''.join(res))