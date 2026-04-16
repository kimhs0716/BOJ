a,b=map(int,input().split()[1:])
print(['Anything','Subway','Bus'][(a!=b)*((a<b)+(a!=b))])