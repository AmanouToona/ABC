import sys

sys.setrecursionlimit(10 ** 8)


def main():
    S = input().strip()

    ans = 0
    for s in S:
        if s == "v":
            ans += 1
        if s == "w":
            ans += 2

    print(ans)

    return


if __name__ == "__main__":
    main()
