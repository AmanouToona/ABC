import sys

sys.setrecursionlimit(10 ** 8)


def main():
    As = list(map(int, sys.stdin.readline().strip().split()))
    As = set(As)

    print(len(As))


if __name__ == "__main__":
    main()
