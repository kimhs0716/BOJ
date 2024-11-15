import sys

input = lambda: sys.stdin.readline().rstrip()

try:
    sys.stdin = open('boj.in', 'r', encoding='utf-8')
    # sys.stdout = open('boj.out', 'w', encoding='utf-8')
    pass
except FileNotFoundError:
    pass


from math import pi

class Time:
    def __init__(self, hh, mm=None):
        if mm is None:
            hh, mm = map(int, hh.split(':'))

        self.hh = hh
        self.mm = mm
        self.angle = self.get_angle()

    def __lt__(self, other):
        return (self.angle, self.hh, self.mm) < (other.angle, other.hh, other.mm)

    def __str__(self):
        return f'{self.hh:02d}:{self.mm:02d}'

    def __repr__(self):
        return f'Time({self.hh:02d}, {self.mm:02d}, {self.angle:.4f})'

    def get_angle(self):
        hh = self.hh % 12
        mm = self.mm

        # 실수 오차를 없애기 위해 실제 각도에 360/pi를 곱해줌
        mm_angle = mm * 12
        hh_angle = hh * 60 + mm

        diff = abs(hh_angle - mm_angle)
        return min(diff, 720 - diff)



tc = int(input())
for _ in range(tc):
    times = list(map(Time, input().split()))
    times.sort()
    # print(times)
    print(times[2])
