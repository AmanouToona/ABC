import sys

sys.setrecursionlimit(10**8)


def main():
    A, B = map(int, input().strip().split())

    for i in range(10):
        if i != A + B:
            print(i)
            return

    return


if __name__ == "__main__":
    main()
