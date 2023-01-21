import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, A, B = map(int, sys.stdin.readline().strip().split())
    S = input().strip()

    ans = float("inf")
    for i in range(N):
        ans_ = A * i

        for j in range(N // 2):
            left = (i + j) % N
            right = (N - 1 - j + i) % N

            if S[left] != S[right]:
                ans_ += B

        ans = min(ans, ans_)

    print(ans)

    return


if __name__ == "__main__":
    main()
