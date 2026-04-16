import re
import sys
input = sys.stdin.readline

p_chain1 = re.compile(r'^1233+4444$')
p_chain2 = re.compile(r'^5566+7777$')

def next_term(s: str) -> str:
    n = int(s)
    n += int(s[::-1])
    return str(int(''.join(sorted(str(n)))))

T = int(input())
for _ in range(T):
    M, s = input().split()
    M = int(M)

    seen = set()
    for idx in range(1, M+1):
        if s in seen:
            print("R", idx)
            break
        if p_chain1.match(s) or p_chain2.match(s):
            print("C", idx)
            break

        seen.add(s)

        if idx == M:
            print(s)
            break

        s = next_term(s)
