s = 0
cnt = 0
t = dict(zip(("A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F", "P"), (4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0, 0.0)))
for _ in range(20):
    sss = input()
    assert '  ' not in sss
    name, score, grade = sss.split()
    if grade == "P":
        cnt -= float(score)
    s += float(score) * t[grade]
    #print(float(score) * t[grade])
    cnt += float(score)
print(s / cnt)

