n = int(input())
study = []
solve = []

for _ in range(n):
    i = input()
    if '/' in i:
        solve.append(i)
    else:
        study.append(i)

study.sort(key=lambda s: (len(s), s))
solve.sort(key=lambda x: int(x.split('/')[1]))
print('\n'.join(study + solve))
