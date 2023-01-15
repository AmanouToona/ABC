import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    S = []
    for _ in range(N):
        S.append(sys.stdin.readline().strip())

    S.reverse()
    for s in S:
        print(s)
    return


if __name__ == "__main__":
    main()
