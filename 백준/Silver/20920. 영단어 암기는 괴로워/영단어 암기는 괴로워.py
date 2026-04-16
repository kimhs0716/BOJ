import sys
input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
word = {}
for _ in range(n):
    w = input()
    if len(w) < m: continue
    if w not in word:
        word[w] = [0, -len(w), w]
    word[w][0] -= 1
print(*map(lambda x: x[2], sorted(word.values())), sep='\n')
