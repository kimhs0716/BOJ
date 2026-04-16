n=int(input())
hap=0
score=0
for _ in range(n):
    a,b,c=map(str,input().split())
    b=int(b)
    hap+=b
    if c[0]=='A':
        s=4.0
    elif c[0]=='B':
        s=3.0
    elif c[0]=='C':
        s=2.0
    elif c[0]=='D':
        s=1.0
    elif c[0]=='F':
        continue
    if c[-1]=='+':
        s+=0.3
    elif c[-1]=='-':
        s-=0.3
    score+=s*b
score/=hap
score = int(score * 100 + 0.5) / 100
print(f'{score:.2f}')