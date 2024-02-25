import sys

sys.setrecursionlimit(10**8)


def main():
    N = int(input())
    P = list(map(int, sys.stdin.readline().strip().split()))

    pos = dict()
    for i, p in enumerate(P):
        pos[p] = i

    Q = int(input())

    for _ in range(Q):
        a, b = map(int, sys.stdin.readline().strip().split())

        if pos[a] > pos[b]:
            print(b)
        else:
            print(a)

    return


if __name__ == "__main__":
    main()
