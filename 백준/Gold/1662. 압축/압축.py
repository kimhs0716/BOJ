import sys
try:
    sys.stdin = open('./boj.in', 'r', encoding='utf-8')
except:
    input = lambda: sys.stdin.readline()[:-1]


def solve(s):
    if '(' not in s: return len(s)
    left = -1
    cnt = 0
    ans = 0
    for idx in range(len(s)):
        if s[idx] == '(':
            cnt += 1
            if left == -1: left = idx
        elif s[idx] == ')':
            cnt -= 1
            if cnt == 0:
                ans += solve(s[left+1:idx]) * int(s[left-1]) - 1
                left = -1
        elif left == -1: ans += 1
    # print(s, ans)
    return ans

s = input()
print(solve(s))
