import sys
input = sys.stdin.readline
record = {}
cnt = 0
for _ in ' ' * int(input()):
    s = input()
    if s == 'ENTER\n':
        record = {}
    else:
        if not s in record:
            record[s] = 0
            cnt += 1
print(cnt)
