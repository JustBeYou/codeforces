for n in range(8):
    for a in range(n):
        for b in range(n):
            for c in range(n):
                for d in range(n):
                    if a | b == c | d and a != b and a != c and a != d and b != c and b != d and c != d:
                        print(a, b, c, d)
