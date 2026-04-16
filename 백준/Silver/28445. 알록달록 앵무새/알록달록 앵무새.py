color = []
exec('color.extend(input().split());' * 2)
color = [*set(color)]
color.sort()

for i in color:
    for j in color:
        print(i, j)
