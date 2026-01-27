import sys
input = lambda: sys.stdin.readline().rstrip()



while True:
    n = int(input())
    if not n: break
    primes = list(map(int, input().split()))
    x, y = map(int, input().split())
    ans = set()
    cur = {1}
    nxt = set()
    while True:
        if not cur: break
        for i in cur:
            for p in primes:
                if i*p <= y:
                    ans.add(i*p)
                    nxt.add(i*p)
        cur = nxt
        nxt = set()
    ans = [1] + sorted(ans)
    ans = [i for i in ans if i>=x]
    if not ans: print("none")
    else:
        print(",".join(map(str, ans)))
    
