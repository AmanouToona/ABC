import sys

sys.setrecursionlimit(10**8)


def main():
    N = int(input())

    ans = []
    for _ in range(N):
        ans.append("1")
        ans.append("0")
    ans.append("1")

    ans = "".join(ans)

    print(ans)

    return


if __name__ == "__main__":
    main()
