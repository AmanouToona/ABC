import sys

sys.setrecursionlimit(10 ** 8)


def main():
    S = input().strip()

    ans = -1
    for i, s in enumerate(S):
        if s == "a":
            ans = i + 1

    print(ans)

    return


if __name__ == "__main__":
    main()
