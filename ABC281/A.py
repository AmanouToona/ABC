import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    for n in range(N, -1, -1):
        print(n)

    return


if __name__ == "__main__":
    main()
