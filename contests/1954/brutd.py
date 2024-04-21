from itertools import chain, combinations
from math import ceil


def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


l = [1, 3, 3, 7]

s = 0
for k in powerset(l):
    if not len(k):
        continue

    x = max(ceil(sum(k)/2), max(k))
    s += x

print(s)
