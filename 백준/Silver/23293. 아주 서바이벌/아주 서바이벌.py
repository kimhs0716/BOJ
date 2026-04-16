import sys

input = sys.stdin.readline


class Player:
    def __init__(self, n):
        self.number = n
        self.items = dict()
        self.pos = 1


cheat_list = set()
ban_list = set()
players = dict()
t, n = map(int, input().split())
for _ in range(t):
    log_num, num, code, *args = input().split()
    num = int(num)
    args = list(map(int, args))
    if num not in players:
        players[num] = Player(num)
    if code == 'M':
        players[num].pos = args[0]
    elif code == 'F':
        if players[num].pos != args[0]:
            cheat_list.add(int(log_num))
        if args[0] not in players[num].items:
            players[num].items[args[0]] = 0
        players[num].items[args[0]] += 1
    elif code == 'C':
        if args[0] in players[num].items and players[num].items[args[0]] >= 1:
            players[num].items[args[0]] -= 1
        else:
            cheat_list.add(int(log_num))
        if args[1] in players[num].items and players[num].items[args[1]] >= 1:
            players[num].items[args[1]] -= 1
        else:
            cheat_list.add(int(log_num))
    elif code == 'A':
        if args[0] not in players:
            players[args[0]] = Player(args[0])
        if players[num].pos != players[args[0]].pos:
            cheat_list.add(int(log_num))
            ban_list.add(int(num))

print(len(cheat_list))
if cheat_list: print(' '.join(map(str, sorted(cheat_list))))
print(len(ban_list))
if cheat_list: print(' '.join(map(str, sorted(ban_list))))
