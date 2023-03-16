import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    cnt = [0] * (N + 1)

    for i in range(1, N + 1):
        for j in range(i, N + 1, i):
            cnt[j] += 1

    # ab = x, cd = y
    ans = 0
    for x in range(1, N + 1):
        y = N - x

        ans += cnt[x] * cnt[y]

    print(ans)

    return


if __name__ == "__main__":
    main()
