import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    root = [0] * (2 + 2 * N)
    root[1] = 0
    for i, a in enumerate(A):
        i += 1
        root[2 * i] = root[a] + 1
        root[2 * i + 1] = root[a] + 1

    for r in root[1:]:
        print(r)

    return


if __name__ == "__main__":
    main()
