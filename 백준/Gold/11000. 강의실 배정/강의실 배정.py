import sys
from queue import PriorityQueue

input = lambda: sys.stdin.readline().strip()

lesson = []
room = PriorityQueue()
n = int(input())
for _ in '_' * n:
    a, b = map(int, input().split())
    lesson.append((a, b))

lesson.sort()

room.put(0)
for le in lesson:
    ro = room.get()
    if le[0] < ro:
        room.put(ro)
        room.put(le[1])
    else:
        room.put(le[1])

print(room.qsize())