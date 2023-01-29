import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    S = []
    for _ in range(N):
        S.append(sys.stdin.readline().strip())

    T = set()
    for _ in range(M):
        T.add(sys.stdin.readline().strip())

    cnt = 0
    for s in S:
        if s[-3:] in T:
            cnt += 1

    print(cnt)

    return


if __name__ == "__main__":
    main()
