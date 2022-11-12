import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A.sort()
    ans = 0
    put = 0
    end = 0
    for start in range(N):
        if end == start:
            put += A[end]
            end += 1
            end %= N

        while end != start and (A[end] - A[end - 1 if end != 0 else N - 1]) % M <= 1:
            put += A[end]
            end += 1
            end %= N

        ans = max(ans, put)
        put -= A[start]

    print(sum(A) - ans)

    return


if __name__ == "__main__":
    main()
