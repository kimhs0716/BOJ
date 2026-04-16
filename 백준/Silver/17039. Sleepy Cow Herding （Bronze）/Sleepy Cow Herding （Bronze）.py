a,b,c,=map(int,input().split())
a,b,c,=sorted((a,b,c))
if a+1==b and b+1==c: m=0
elif a+2==b or b+2==c: m=1
else: m=2
M=max(b-a,c-b)-1
print(m)
print(M)