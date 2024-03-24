from random import shuffle, randint

t = 100_000
n = int(5)
a = [i for i in range(1, n + 1)]
a = a + a

print(t)

k = randint(1, n // 2)

for _ in range(t):
  print(n, k)
  shuffle(a)
  print(' '.join(map(str, a))) 