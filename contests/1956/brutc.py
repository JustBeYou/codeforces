from itertools import permutations, product, combinations

for n in range(1, 4):
    a = [[0 for _ in range(n)] for _ in range(n)]

    p = list(permutations(range(1, n+1)))

    p1 = list(product(p, repeat=n))

    p2 = []
    for i in range(1, n+1):
        p2.extend(combinations(p, i))

    bs = 0
    for q in p1:
        for i in range(n):
            for j in range(n):
                a[i][j] = q[i][j]

        for w in p2:
            # print(q, w)

            for i in range(len(w)):
                for j in range(n):
                    a[j][i] = w[i][j]

            s = [sum(i) for i in a]
            s = sum(s)
            bs = max(s, bs)

    print(n, " -> ", bs)
