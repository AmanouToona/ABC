import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(sys.stdin.readline().strip())
    s = hex(N)
    s = s[2:]
    s = s.upper()
    if len(s) == 1:
        print("0", end="")
    print(f"{s}")
    return


if __name__ == "__main__":
    main()
