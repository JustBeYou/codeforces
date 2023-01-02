#!/usr/bin/env python3

from sys import argv
from os import system

def help():
  print(f"Usage: {argv[0]} [g(enerate)|r(un)][c(ontest)|p(roblem)] <id> [problem]")
  exit()

if len(argv) < 4:
  help()

cmd = argv[1]
t = argv[2]
i = argv[3]

if cmd == "g":
  if t == "c":
    system(f"mkdir -p contests/{i}")
    for c in "ABCDEF":
      system(f"cp template.cpp contests/{i}/{c}.cpp")
    system(f"touch contests/{i}/input")
  elif t == "p":
    system(f"mkdir -p problems/{i}")
    system(f"cp template.cpp problems/{i}/main.cpp")
    system(f"touch problems/{i}/input")
  else:
    help()
elif cmd == "r":
  if t == "c":
    p = argv[4]
    system(f"cd contests/{i} && g++ -Wall -Wextra {p}.cpp -DDEBUG -o {p} && ./{p} && rm ./{p}")
  elif t == "p":
    system(f"cd problems/{i} && g++ -Wall -Wextra main.cpp -DDEBUG -o main && ./main && rm ./main")
  else:
    help()
else:
  help()

