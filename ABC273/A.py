import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    ans = [1] * (N + 1)

    for i in range(1, N + 1):
        ans[i] = i * ans[i - 1]

    print(ans[N])

    return


if __name__ == "__main__":
    main()
