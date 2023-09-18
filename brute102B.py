def sum_digits(x):
    print(x, end=" -> ")
    c = 0
    while x > 9:
        c += 1
        s, y = 0, x
        while y > 0:
            s += y % 10
            y //= 10
        x = s
        print(x, end=" -> ")
    print(f"({c})")

sum_digits(int("9" * int(1e3) + "8" * int(1e3)))
