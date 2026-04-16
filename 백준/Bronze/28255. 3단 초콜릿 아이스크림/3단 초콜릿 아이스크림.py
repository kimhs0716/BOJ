for _ in '_' * int(input()):
    s = input()
    sp = s[:len(s) // 3 + int(len(s) % 3 != 0)]
    a = (
        sp + sp[::-1] + sp,
        sp + sp[::-1][1:] + sp,
        sp + sp[::-1] + sp[1:],
        sp + sp[::-1][1:] + sp[1:]
        )
    print(int(s in a))
