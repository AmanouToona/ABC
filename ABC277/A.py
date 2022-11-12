import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, X = map(int, sys.stdin.readline().strip().split())
    P = list(map(int, sys.stdin.readline().strip().split()))

    for i, p in enumerate(P):
        if p == X:
            print(i + 1)
            return

    return


if __name__ == "__main__":
    main()
