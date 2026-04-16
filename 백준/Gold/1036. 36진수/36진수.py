int2char = [str(i) for i in range(10)]
for i in range(10, 36):
    int2char.append(chr(i + ord('A') - 10))

def to_string(n):
    if n < 36: return int2char[n]
    return to_string(n // 36) + int2char[n % 36]

def cmp(x):
    if x[0] == 35:
        return float('inf')
    res = 0
    for i in range(50, 0, -1):
        res *= 36
        res += x[i]
    return -res * (35 - x[0])

cnt = [[0] * 51 for _ in range(36)]
for i in range(36):
    cnt[i][0] = i

n = int(input())
arr = []
for i in range(n):
    s = input()
    arr.append(s)
    for j in range(len(s)):
        cnt[int(s[j], 36)][len(s) - j] += 1
cnt.sort(key=cmp)
k = int(input())
change = [int2char[x[0]] for x in cnt[:k]]
for i in range(n):
    for j in change:
        arr[i] = arr[i].replace(j, 'Z')
# print(*arr, sep='\n')
s = 0
for i in arr:
    s += int(i, 36)
print(to_string(s))
