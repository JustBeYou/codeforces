from itertools import product

s = 9999999999999
n = 98
q = None

for a,b,c,d,e in product(range(7), repeat=5):
  #print(a,b,c,d,e)

  k = a+b+c+d+e
  if a+b*3+c*6+d*10+e*15 == n and k < s:
    s = k
    q = [a,b,c,d,e]
  

print(s, q)