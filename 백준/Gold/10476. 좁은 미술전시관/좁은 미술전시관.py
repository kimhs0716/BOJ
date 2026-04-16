import sys
input = lambda: sys.stdin.readline().rstrip()

while True:
    n, k = map(int, input().split())
    if n == 0 and k == 0: break
    arr = [list(map(int, input().split())) for _ in range(n)]

    # dp[n][3][k] -> n번째 칸의 문 상태, k칸 선택 했을 때의 최댓값
    # 0 -> 둘다 선택 x, 1 -> 0번칸 선택, 2 -> 1번칸 선택
    dp = [[-float('inf')] * (k + 2) for _ in range(3)]
    dp[0][0] = sum(arr[0])
    dp[1][1] = arr[0][1]
    dp[2][1] = arr[0][0]

    for i in range(1, n):
        new = [[-float('inf')] * (k + 2) for _ in range(3)]
        for j in range(k + 1): new[0][j] = max((dp[0][j], dp[1][j], dp[2][j])) + arr[i][0] + arr[i][1]
        for j in range(k): new[1][j + 1] = max(dp[0][j], dp[1][j]) + arr[i][1]
        for j in range(k): new[2][j + 1] = max(dp[0][j], dp[2][j]) + arr[i][0]
        dp = new

    print(max(dp[0][k], dp[1][k], dp[2][k]))
