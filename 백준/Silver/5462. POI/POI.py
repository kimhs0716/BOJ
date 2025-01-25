import sys

input = lambda: sys.stdin.readline().rstrip()
inf = float('inf')

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
except FileNotFoundError:
    pass


def get_problem_scores(info):
    ret = [0] * t
    for i in range(n):
        for j in range(t):
            ret[j] += info[i][j] ^ 1
    return ret

def get_user_scores(info, problem_scores):
    ret = [0] * n
    for i in range(n):
        for j in range(t):
            ret[i] += problem_scores[j] * info[i][j]
    return ret

n, t, p = map(int, input().split())
p -= 1
info = [list(map(int, input().split())) for _ in range(n)]

problem_scores = get_problem_scores(info)
user_scores = get_user_scores(info, problem_scores)
user_counts = [0] * n
for i in range(n):
    for j in range(t):
        user_counts[i] += info[i][j]

user_info = [(user_scores[i], user_counts[i], -i) for i in range(n)]

# print(*user_info)

ans = 1
for i in range(n):
    if user_info[i] > user_info[p]: ans += 1
    # print(user_info[i], user_info[i] > user_info[p], user_info[p])
#
print(user_scores[p], ans)
