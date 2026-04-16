import sys
input = lambda: sys.stdin.readline()[:-1]


n, q = map(int, input().split())
sqrt_n = int(n ** 0.5) + 1
counts = [0] * sqrt_n
arr = [[-1] * sqrt_n for _ in range(sqrt_n)]

ans = []

for time in range(1, q + 1):
    # print(counts)
    # print(arr)
    t, i = map(int, input().split())
    i -= 1
    if t == 1:
        idx, idx2 = divmod(i, sqrt_n)
        while idx * sqrt_n + idx2 < n:
            if arr[idx][idx2] == -1:
                arr[idx][idx2] = time
                # print(idx * sqrt_n + idx2 + 1)
                ans.append(str(idx * sqrt_n + idx2 + 1))
                counts[idx] += 1
                break
            idx2 += 1
            if idx2 == sqrt_n:
                idx += 1
                idx2 = 0
                while counts[idx] == sqrt_n:
                    idx += 1
                    if idx == sqrt_n: break
            if idx == sqrt_n or idx * sqrt_n + idx2 >= n:
                    # print(-1)
                    ans.append("-1")
                    break

    else:
        idx, idx2 = divmod(i, sqrt_n)
        # print(arr[idx][idx2])
        ans.append(str(arr[idx][idx2]))
        if arr[idx][idx2] != -1:
            counts[idx] -= 1
        arr[idx][idx2] = -1

sys.stdout.write("\n".join(ans))
