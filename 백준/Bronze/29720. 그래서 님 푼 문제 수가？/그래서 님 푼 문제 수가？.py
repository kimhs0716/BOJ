n, m, k = map(int, input().split())

mm = n - m * k
MM = mm + m - 1

print(f'{max(mm, 0)} {max(MM, 0)}')
