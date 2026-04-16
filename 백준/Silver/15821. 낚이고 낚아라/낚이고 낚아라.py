import sys
input = sys.stdin.readline

def dis(t):
    x, y = t
    return x * x + y * y

n, k = map(int, input().split())
arr = []
for i in range(n):
    m = int(input())
    tmp = []
    tarr = list(map(int, input().split()))
    for i in range(m):
        tmp.append((tarr[i * 2], tarr[i * 2 + 1]))
    tmp.sort(key=dis)
    arr.append(tmp[-1])

arr.sort(key=dis)
print('%d.00' % dis(arr[k - 1]))