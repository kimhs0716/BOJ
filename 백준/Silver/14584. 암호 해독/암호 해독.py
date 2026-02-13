import sys
input = lambda: sys.stdin.readline().rstrip()


from string import ascii_lowercase as abc


s = input()
s = [ord(i) - 97 for i in s]
n = int(input())
words = [input() for _ in range(n)]

for i in range(26):
    t = ''.join(abc[(j+i)%26] for j in s)
    if any(map(lambda w: w in t, words)):
        print(t)
        break
