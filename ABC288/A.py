import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    for _ in range(N):
        A, B = map(int, sys.stdin.readline().strip().split())
        print(A + B)
    return


if __name__ == "__main__":
    main()
