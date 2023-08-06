#!/usr/bin/env python3

from os import system
from sys import argv


def help():
    print(
        f"Usage: {argv[0]} [g(enerate)|r(un)][c(ontest)|p(roblem)] <id> [problem] [c|hs]")
    exit()


if len(argv) < 4:
    help()

cmd = argv[1]
t = argv[2]
i = argv[3]

lng = argv[-1]
if lng not in ["cpp", "hs"]:
    lng = "cpp"

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
        if lng == "cpp":
            system(
                f"cd contests/{i} && g++ -Wall -Wextra {p}.cpp -DDEBUG -o {p}.elf && ./{p}.elf && rm ./{p}.elf")
        elif lng == "hs":
            system(
                f"cd contests/{i} && ghc {p}.hs -DDEBUG -o {p}.elf && ./{p}.elf && rm ./{p}.elf")
    elif t == "p":
        if lng == "cpp":
            system(
                f"cd problems/{i} && g++ -Wall -Wextra main.cpp -DDEBUG -o main.elf && ./main.elf && rm ./main.elf")
        elif lng == "hs":
            system(
                f"cd problems/{i} && ghc main.hs -DDEBUG -o main.elf && cat ./input | ./main.elf && rm ./main.o ./main.hi ./main.elf")
    else:
        help()
else:
    help()
