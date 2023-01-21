import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    S = input().strip()

    S = S.replace("na", "nya")
    print(S)

    return


if __name__ == "__main__":
    main()
