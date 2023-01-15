import sys

sys.setrecursionlimit(10 ** 8)


def solve():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    ans = 0
    for a in A:
        if a % 2 == 1:
            ans += 1

    print(ans)
    return


def main():
    T = int(input())
    for _ in range(T):
        solve()
    return


if __name__ == "__main__":
    main()
