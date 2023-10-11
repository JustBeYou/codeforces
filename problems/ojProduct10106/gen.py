import random

a = []
b = []

for i in range(50):
    x = random.randint(2**36, 2**40)
    y = random.randint(2**36, 2**40)

    a.append(x)
    a.append(y)
    b.append(x*y)

with open("input", "w") as f:
    f.write('\n'.join(map(str, a)))

with open("output", "w") as f:
    f.write('\n'.join(map(str, b)))
