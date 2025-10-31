n, k = map(int, input().split())
ans = ['a'] * (n-k)
for i in range(k):
    ans.append(chr(97+i))
print(''.join(ans))