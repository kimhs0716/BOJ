import sys
input = lambda: sys.stdin.readline().rstrip()

def cmp(s, t):
    if len(s) != len(t): return len(s) < len(t)
    return s < t

for tc in range(int(input())):
    n = int(input())

    arr = [input().upper() for _ in range(n)]
    ans = dict()

    for s in arr:
        ans[s] = "z"*101
        for i in range(len(s)+1):
            for j in range(i, len(s)+1):
                key = s[i:j]
                if cmp(ans[s], key):
                    continue
                flag = True
                for t in arr:
                    if t==s: continue
                    if key in t:
                        flag = False
                        break
                if flag:
                    ans[s] = key
        if len(ans[s]) > 100:
            ans[s] = ":("
        else:
            ans[s] = f'"{ans[s]}"'

    print(f"Case #{tc+1}:")
    for s in arr:
        print(ans[s])
