s = input()
n = len(s)
vowels = [i for i in range(n) if s[i] in 'aiueo']
target = 2 if s[-1] in 'aiueons' else 1
if len(vowels) < target: print(-1)
else: print(vowels[-target]+1)