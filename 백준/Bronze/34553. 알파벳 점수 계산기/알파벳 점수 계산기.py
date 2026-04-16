s=input()
ans,cur=1,1
for i in range(1,len(s)):
    if s[i-1]<s[i]: cur+=1
    else: cur=1
    ans += cur
print(ans)