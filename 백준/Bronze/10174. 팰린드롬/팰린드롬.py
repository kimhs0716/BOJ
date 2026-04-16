for _ in range(int(input())):
    s = input().lower()
    print("YNeos"[s!=s[::-1]::2])