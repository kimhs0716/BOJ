import sys
input = lambda: sys.stdin.readline()[:-1]


for _ in range(int(input())):
    n, s, e = map(int, input().split())

    # i) S와 E가 양 끝에 있는 경우 -> 0
    if {s, e} == {1, n}:
        print(0)

    # ii) s랑 e가 붙어있는 경우 -> 1
    elif abs(s - e) == 1:
        print(1)

    # iii) s만 끝에 있는 경우  -> 1
    elif s in {1, n}:
        print(1)

    # iv) 그 밖의 경우 -> 2
    else:
        print(2)
