s = []
medal = []
N = int(input())
for _ in range(N):
    arr = list(map(int, input().split()))
    arr = arr[::-1]
    s.append(arr)

s.sort(reverse=True)

medal.append(s[0])
medal.append(s[1])

i = 2
while True:
    if s[0][2] == s[1][2] == s[i][2]:
        i += 1
    else:
        medal.append(s[i])
        break

for j in range(3):
    print(int(medal[j][2]), end=' ')
    print(int(medal[j][1]))