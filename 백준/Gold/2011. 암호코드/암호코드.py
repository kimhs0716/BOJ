MOD = int(1e6)

s = input()
if s[0] == '0':
    print(0)
elif len(s) == 1:
    print(1)
else:
    dp = [[0, 0] for _ in s]
    dp[0][0] = 1
    dp[0][1] = 0
    dp[1][0] = int(s[1] != '0')
    if int(s[0] + s[1]) <= 26:
        dp[1][1] = 1
    for i in range(2, len(s)):
        if s[i] != '0':
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1]
        if 10 <= int(s[i - 1] + s[i]) <= 26:
            dp[i][1] = dp[i - 2][0] + dp[i - 2][1]
        dp[i][0] %= MOD
        dp[i][1] %= MOD
    print(sum(dp[-1]) % MOD)
