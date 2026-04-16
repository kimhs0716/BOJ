cnt = 0
n = int(input())
s = input()
song = list(s)

def check(song, i):
    global s
    for j in range(i, len(song)):
        if j - i >= len(s): break
        if s[j - i] != song[j]: return False
    return True

for i in range(n):
    if check(song, i):
        cnt += 1
        for j in range(n - i, n):
            song.append(s[j])

print(cnt)
