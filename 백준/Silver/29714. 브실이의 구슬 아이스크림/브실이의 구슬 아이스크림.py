import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
m = dict()
for i in map(int, input().split()):
    if i not in m:
        m[i] = 0
    m[i] += 1
q = int(input())
for _ in range(q):
    a, *A = map(int, input().split())
    mm = dict()
    for j in A:
        if j not in mm:
            mm[j] = 0
        mm[j] += 1
    flag = False
    for i, j in mm.items():
        if i not in m or j > m[i]: break
    else:
        flag = True
        for i, j in mm.items():
            m[i] -= j
    b, *B = map(int, input().split())
    if flag == True:
        for j in B:
            if j not in m:
                m[j] = 0
            m[j] += 1

cnt = 0
ans = []
for i, j in m.items():
    cnt += j
    for _ in range(j): ans.append(str(i))

print(cnt)
print(' '.join(ans))
