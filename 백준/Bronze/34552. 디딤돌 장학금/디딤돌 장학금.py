a=list(map(int, input().split()))
ans=0
for _ in range(int(input())):
    b, l, s = input().split()
    if float(l)>=2 and int(s)>=17:
        ans += a[int(b)]
print(ans)