import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass

# 1. 풀매도 -> X
# 2. 풀매도 -> 영끌 -> 풀매수
# 3. X -> X
# 4. X -> 영끌 -> 풀매수

def solve(cur, m, stock, debt): # 현재 날짜 (0 ~ n-1), 현재 돈, 대출 배율, 보유 주식 수, 현재 빚
    # print(cur, m, stock, debt)

    if cur == n - 1:
        return m + arr[cur] * stock

    ans = m

    # 1. 풀매도 -> X
    m1 = m + arr[cur] * stock
    if m1 >= 0: ans = max(ans, solve(cur + 1, m1, 0, debt))

    # 2. 풀매도 -> 영끌 -> 풀매수
    m1 -= debt
    d1 = m1 * k
    m1 += d1
    s1, m1 = divmod(m1, arr[cur])
    if s1 > 0 and m1 >= 0: ans = max(ans, solve(cur + 1, m1, s1, d1))

    # 3. X -> X
    ans = max(ans, solve(cur + 1, m, stock, debt))

    # 4. X -> 영끌 -> 풀매수
    m -= debt
    debt = m * k
    m += debt
    stock, m = divmod(m, arr[cur])
    if stock > 0 and m >= 0: ans = max(ans, solve(cur + 1, m, stock, debt))

    return ans

n, m, k = map(int, input().split())
arr = list(map(int, input().split()))

print(solve(0, m, 0, 0))
