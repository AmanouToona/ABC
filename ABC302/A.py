import sys

sys.setrecursionlimit(10**8)


def main():
    A, B = map(int, sys.stdin.readline().strip().split())

    if A % B == 0:
        print(A // B)
    else:
        print(A // B + 1)
    return


if __name__ == "__main__":
    main()
