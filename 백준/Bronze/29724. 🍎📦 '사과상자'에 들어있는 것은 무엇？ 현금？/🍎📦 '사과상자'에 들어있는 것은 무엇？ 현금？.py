cnt = 0
mass = 0
for _ in range(int(input())):
    s = input().split()
    if s[0] == 'A':
        cnt += (int(s[1]) // 12) * (int(s[2]) // 12) * (int(s[3]) // 12)
        mass += 1000
    else:
        mass += 6000

print(mass + cnt * 500)
print(cnt * 4000)
