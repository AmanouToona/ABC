import sys

sys.setrecursionlimit(10 ** 8)


def main():
    a, b, c, d = map(int, sys.stdin.readline().strip().split())
    print((a + b) * (c - d))
    print("Takahashi")
    return


if __name__ == "__main__":
    main()
