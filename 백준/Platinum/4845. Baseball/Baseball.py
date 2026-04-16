def random_generator():
    x = 1
    while 1:
        x = (x * 25173 + 13849) % 65536
        yield x

t = int(input())
for _ in range(t):
    team1 = input()
    t1players = []
    for i in range(9):
        t1players.append(input().split())
        t1players[-1][1] = int(t1players[-1][1][1:]) / 1000
        t1players[-1][2] = int(t1players[-1][2][1:]) / 1000
    team2 = input()
    t2players = []
    for i in range(9):
        t2players.append(input().split())
        t2players[-1][1] = int(t2players[-1][1][1:]) / 1000
        t2players[-1][2] = int(t2players[-1][2][1:]) / 1000
    print(f'Game {_ + 1}: {team1} vs. {team2}\n')

    random = random_generator()
    inning = 1
    batter = [0, 0]
    hits = [0, 0]
    runs = [0, 0]
    while True:
        hitter = [[], []]
        runner = [[], []]
        out = 0
        base = ['', '', '', '']
        while True:
            if out == 0 and base[2] or out <= 1 and base[3]:
                if next(random) / 65536 <= t1players[batter[0]][2]:
                    if base[3]:
                        runner[0].append(base[3])
                        runs[0] += 1
                        base[3] = ''
                    if base[2]:
                        base[3] = base[2]
                        base[2] = ''
                    
                    if base[1]:
                        base[2] = base[1]
                        base[1] = ''
                out += 1
            else:
                if next(random) / 65536 <= t1players[batter[0]][1]:
                    hitter[0].append(t1players[batter[0]][0])
                    hits[0] += 1
                    if base[3]:
                        runner[0].append(base[3])
                        runs[0] += 1
                        base[3] = ''
                    if base[2]:
                        base[3] = base[2]
                        base[2] = ''
                    
                    if base[1]:
                        base[2] = base[1]
                        base[1] = ''
                    base[1] = t1players[batter[0]][0]
                else:
                    out += 1
            batter[0] = (batter[0] + 1) % 9
            if out == 3: break
        out = 0
        base = ['', '', '', '']
        if inning >= 9 and runs[0] < runs[1]:
            pass
        else:
            while True:
                if out == 0 and base[2] or out <= 1 and base[3]:
                    if next(random) / 65536 <= t2players[batter[1]][2]:
                        if base[3]:
                            runner[1].append(base[3])
                            runs[1] += 1
                            base[3] = ''
                        if base[2]:
                            base[3] = base[2]
                            base[2] = ''
                            
                        if base[1]:
                            base[2] = base[1]
                            base[1] = ''
                    out += 1
                else:
                    if next(random) / 65536 <= t2players[batter[1]][1]:
                        hitter[1].append(t2players[batter[1]][0])
                        hits[1] += 1
                        if base[3]:
                            runner[1].append(base[3])
                            runs[1] += 1
                            base[3] = ''
                        if base[2]:
                            base[3] = base[2]
                            base[2] = ''
                            
                        if base[1]:
                            base[2] = base[1]
                            base[1] = ''
                        base[1] = t2players[batter[1]][0]
                    else:
                        out += 1
                batter[1] = (batter[1] + 1) % 9
                if out == 3: break
        print(f'Inning {inning}:')
        # print(f'#[DEBUG]: score = {runs}')
        print('Hits:')
        if len(hitter[0]) + len(hitter[1]) == 0:
            print('  none')
        else:
            for i in hitter[0]:
                print("  %15s %15s" % (i, team1))
            for i in hitter[1]:
                print("  %15s %15s" % (i, team2))
        print()
        print('Runs:')
        if len(runner[0]) + len(runner[1]) == 0:
            print('  none')
        else:
            for i in runner[0]:
                print("  %15s %15s" % (i, team1))
            for i in runner[1]:
                print("  %15s %15s" % (i, team2))
        print()
        inning += 1
        if inning >= 10 and runs[0] != runs[1]: break
    print('End of Game:')
    print('  %15s %d runs, %d hits' % (team1, runs[0], hits[0]))
    print('  %15s %d runs, %d hits' % (team2, runs[1], hits[1]))
    if _ != t - 1: print('=' * 60)
print()
