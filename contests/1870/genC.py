from random import randint

t = 100
n = 10
k = 15

print(t)

for i in range(t):
    print(n, k)
    for j in range(n):
        print(randint(1, k), end=' ')
    print()
