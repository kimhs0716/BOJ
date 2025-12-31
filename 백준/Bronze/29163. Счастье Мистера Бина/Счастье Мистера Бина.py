n=int(input())
o=sum(x%2for x in map(int,input().split()))
print(['Sad','Happy'][n-o>o])