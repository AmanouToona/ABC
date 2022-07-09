import sys


def main():
    N, M, X, T, D = list(map(int, sys.stdin.readline().strip().split()))
    ans = T - D * max(0, (N - M) - (N - X))
    print(ans)
    return


if __name__ == "__main__":
    main()
