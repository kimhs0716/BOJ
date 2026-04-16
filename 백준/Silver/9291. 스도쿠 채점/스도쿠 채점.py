def check(arr):
    if not check1(arr): return False
    if not check2(arr): return False
    if not check3(arr): return False
    return True

def check1(arr):
    for r in range(9):
        s = set(arr[r])
        if len(s) != 9: return False
    return True

def check2(arr):
    for c in range(9):
        s = set()
        for r in range(9):
            s.add(arr[r][c])
        if len(s) != 9: return False
    return True

def check3(arr):
    for r in range(3):
        for c in range(3):
            s = set()
            for i in range(9):
                s.add(arr[r * 3 + i // 3][c * 3 + i % 3])
            if len(s) != 9: return False
    return True

T = int(input())

for tc in range(T):
    arr = [list(map(int, input().split())) for __ in range(9)]
    if tc != T - 1: input()
    print(f'Case {tc + 1}: {"IN" * (not check(arr))}CORRECT')
