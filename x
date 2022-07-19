#!/usr/bin/env python3

from sys import argv
from os import system

def help():
  print(f"Usage: {argv[0]} [c(ontest)|p(roblem)] <id>")
  exit()

if len(argv) < 3:
  help()

t = argv[1]
i = argv[2]

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