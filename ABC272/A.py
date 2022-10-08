import sys

sys.setrecursionlimit(10 ** 8)


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))
    print(sum(A))
    return


if __name__ == "__main__":
    main()
