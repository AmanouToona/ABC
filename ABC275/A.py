import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    H = list(map(int, sys.stdin.readline().strip().split()))

    print(H.index(max(H)) + 1)

    return


if __name__ == "__main__":
    main()
