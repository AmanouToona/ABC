import sys

sys.setrecursionlimit(10 ** 8)


def main():
    S = input().strip()
    S = list(S)

    for i in range(len(S) // 2):
        S[2 * i + 1], S[2 * i] = S[2 * i], S[2 * i + 1]

    S = "".join(S)
    print(S)

    return


if __name__ == "__main__":
    main()
