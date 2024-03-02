import sys

sys.setrecursionlimit(10**8)


def main():
    N = int(input())
    A = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(N)]

    for a in A:
        ans = []
        for i, a_ in enumerate(a):
            if a_ == 1:
                ans.append(i + 1)

        print(" ".join(map(str, ans)))

    return


if __name__ == "__main__":
    main()
