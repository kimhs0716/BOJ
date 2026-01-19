import sys
input = lambda: sys.stdin.readline().rstrip()


MOD = 998_244_353


def f(a, b):
    arr = [[-1] * b for _ in range(a)]
    return bt(arr, 0, 0, a, b)

def bt(arr, i, j, a, b):
    if i==a:
        return 1
    ch = 'KPC'
    ret = 0
    nj = (j+1)%b
    ni = i+(j==b-1)
    if i==0 or j==0:
        for c in ch:
            arr[i][j] = c
            ret += bt(arr, ni, nj, a, b)
    else:
        cnt = [1, 1, 2]
        cnt[ch.find(arr[i-1][j-1])] -= 1
        cnt[ch.find(arr[i][j-1])] -= 1
        cnt[ch.find(arr[i-1][j])] -= 1
        if cnt==[1, 0, 0]: arr[i][j] = 'K'
        elif cnt==[0, 1, 0]: arr[i][j] = 'P'
        elif cnt==[0, 0, 1]: arr[i][j] = 'C'
        else: return ret
        ret += bt(arr, ni, nj, a, b)
    return ret




MAX = 100000+100
diff = [(pow(2, i+3, MOD) + pow(2, (i+1)//2, MOD)*(i&1)) % MOD for i in range(MAX)]
# print(diff)
t = [10]
for i in range(len(diff)):
    t.append((diff[i]+t[-1])%MOD)
diff = t
# print(diff)

pre = [0]
for i in range(len(diff)):
    pre.append((pre[-1]+diff[i])%MOD)

# print(pre)

for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = 12
    ans = (ans+pre[n-2])%MOD
    ans = (ans+pre[m-2])%MOD
    print(ans)
