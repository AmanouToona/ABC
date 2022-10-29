import sys

sys.setrecursionlimit(10 ** 8)


def main():
    A, B = map(int, sys.stdin.readline().strip().split())

    print(f"{B / A:.3f}")

    return


if __name__ == "__main__":
    main()
