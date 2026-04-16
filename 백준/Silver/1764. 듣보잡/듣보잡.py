import sys
input = sys.stdin.readline
result = ""
n, m = map(int, input().split())
never_heard = set()
never_seen = set()
for i in range(n):
    never_heard.add(input())
for i in range(m):
    never_seen.add(input())
never_heard_seen = never_heard & never_seen
result += str(len(never_heard_seen)) + "\n"
for i in sorted(list(never_heard_seen)):
    result += i
print(result[:-1])
