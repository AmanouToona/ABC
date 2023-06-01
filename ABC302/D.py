import sys

sys.setrecursionlimit(10**8)


def main():
    N, M, D = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    B = list(map(int, sys.stdin.readline().strip().split()))

    A.sort()
    B.sort()

    r = 0
    ans = -1
    for a in A:
        while r + 1 < M and B[r + 1] <= a + D:
            r += 1

        if abs(a - B[r]) > D:
            continue

        ans = max(ans, a + B[r])

    print(ans)

    return


if __name__ == "__main__":
    main()
