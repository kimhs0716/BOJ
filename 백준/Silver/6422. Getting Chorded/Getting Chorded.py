chord2int_dict = dict(zip('C C# D D# E F F# G G# A A# B'.split(), range(0, 12)))
int2chord_dict = dict(zip(range(0, 12), 'C C# D D# E F F# G G# A A# B'.split()))


def chord2int(chord):
    if len(chord) == 2 and chord[-1] == 'b':
        chord = flat2sharp(chord)
    chord = chord.upper()
    return chord2int_dict[chord]


def flat2sharp(s):
    return int2chord_dict[chord2int_dict[s[0].upper()] - 1]


minors = {(0, 3, 7): 'C', (1, 4, 8): 'C#', (2, 5, 9): 'D', (3, 6, 10): 'D#', (4, 7, 11): 'E', (0, 5, 8): 'F',
          (1, 6, 9): 'F#', (2, 7, 10): 'G', (3, 8, 11): 'G#', (0, 4, 9): 'A', (1, 5, 10): 'A#', (2, 6, 11): 'B'}
majors = {(0, 4, 7): 'C', (1, 5, 8): 'C#', (2, 6, 9): 'D', (3, 7, 10): 'D#', (4, 8, 11): 'E', (0, 5, 9): 'F',
          (1, 6, 10): 'F#', (2, 7, 11): 'G', (0, 3, 8): 'G#', (1, 4, 9): 'A', (2, 5, 10): 'A#', (3, 6, 11): 'B'}

while True:
    try:
        a, b, c = input().split()
        d, e, f = map(chord2int, (a, b, c))
        s = tuple(sorted([d, e, f]))
        if s in majors:
            print(f'{a} {b} {c} is a {majors[s]} Major chord.')
        elif s in minors:
            print(f'{a} {b} {c} is a {minors[s]} Minor chord.')
        else:
            print(f'{a} {b} {c} is unrecognized.')
    except Exception:
        break
