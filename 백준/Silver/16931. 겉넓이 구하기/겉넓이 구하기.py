N, M = map(int, input().split())
block = []
for i in range(N):
    block.append(list(map(int, input().split())))

# 겉넓이 = 6 * (전체 블록 개수) - 2 * (인접한 블록 개수)
# 인접한 블록 개수 = (인접한 블록의 수 - 1) * 2
total = 0
for i in range(N):
    for j in range(M):
        if block[i][j] != 0:
            total += 6 * block[i][j] - 2 * (block[i][j] - 1)
            if i != 0:
                total -= 2 * min(block[i][j], block[i - 1][j])
            if j != 0:
                total -= 2 * min(block[i][j], block[i][j - 1])
print(total)