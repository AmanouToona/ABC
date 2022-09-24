import sys

sys.setrecursionlimit(10**8)


def main():
    N, _ = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A = list(reversed(A))

    a = 0
    taka = 1
    ans = 0
    while N > 0:
        while A[a] > N:
            a += 1

        if taka:
            ans += A[a]

        N -= A[a]

        taka = 1 - taka

    print(ans)

    return


if __name__ == "__main__":
    main()
