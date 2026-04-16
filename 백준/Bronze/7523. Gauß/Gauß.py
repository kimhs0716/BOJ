for i in range(int(input())):
    a, b = map(int, input().split())
    print(f'Scenario #{i + 1}:')
    print((a + b) * (b - a + 1) // 2)
    print()
