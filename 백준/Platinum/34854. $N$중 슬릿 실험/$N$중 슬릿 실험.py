import sys
input = lambda: sys.stdin.readline().rstrip()


INF = 10**18

def dist(a, b):
    dx = a[0]-b[0]
    dy = a[1]-b[1]
    return (dx*dx+dy*dy)**0.5

def ccw(a, b, c):
    return (b[0]-a[0])*(c[1]-a[1]) - (b[1]-a[1])*(c[0]-a[0])

m, n = map(int, input().split())
left = [[0, 0]]
right = [[0, 0]]
for i in range(1, n+1):
    l, r = map(int, input().split())
    left.append([l, i])
    right.append([r, i])
left.append([0, n+1])
right.append([0, n+1])

dp = [[INF, INF] for _ in range(n+2)]
dp[0] = [0, 0]

for i in range(1, n+2):
    for j in range(i):
        # left[j] -> left[i]
        flag = True
        for k in range(j, i):
            if ccw(left[j], left[i], left[k]) * ccw(left[j], left[i], right[k]) > 0:
                flag = False
                break
        if flag:
            dp[i][0] = min(dp[i][0], dp[j][0]+dist(left[j], left[i]))

        # right[j] -> left[i]
        flag = True
        for k in range(j, i):
            if ccw(right[j], left[i], left[k]) * ccw(right[j], left[i], right[k]) > 0:
                flag = False
                break
        if flag:
            dp[i][0] = min(dp[i][0], dp[j][1]+dist(right[j], left[i]))

        # left[j] -> right[i]
        flag = True
        for k in range(j, i):
            if ccw(left[j], right[i], left[k]) * ccw(left[j], right[i], right[k]) > 0:
                flag = False
                break
        if flag:
            dp[i][1] = min(dp[i][1], dp[j][0]+dist(left[j], right[i]))

        # right[j] -> right[i]
        flag = True
        for k in range(j, i):
            if ccw(right[j], right[i], left[k]) * ccw(right[j], right[i], right[k]) > 0:
                flag = False
                break
        if flag:
            dp[i][1] = min(dp[i][1], dp[j][1]+dist(right[j], right[i]))

print(min(dp[n+1]))
