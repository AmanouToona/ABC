import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    cusum = [0] + A
    for i in range(N):
        cusum[i + 1] += cusum[i]

    ans = -float("inf")

    b_sum = 0
    for m in range(M):
        b_sum += A[m] * (m + 1)

    ans = b_sum

    for right in range(M, N):
        b_sum += A[right] * M
        b_sum -= cusum[right] - cusum[right - M]

        ans = max(ans, b_sum)

    print(ans)

    return


if __name__ == "__main__":
    main()
