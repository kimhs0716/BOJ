import sys
input = lambda: sys.stdin.readline().rstrip()


MOD = 998_244_353
MAX = 100000+100
diff = [(pow(2, i+3, MOD) + pow(2, (i+1)//2, MOD)*(i&1)) % MOD for i in range(MAX)]
# print(diff)
temp = [10]
for i in range(len(diff)):
    temp.append((diff[i]+temp[-1])%MOD)
diff = temp
# print(diff)

arr = [0]
for i in range(len(diff)):
    arr.append((arr[-1]+diff[i])%MOD)

# print(arr)

for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = 12
    ans = (ans+arr[n-2])%MOD
    ans = (ans+arr[m-2])%MOD
    print(ans)
