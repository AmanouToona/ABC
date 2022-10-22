import sys

sys.setrecursionlimit(10**8)


def main():
    H, W = map(int, sys.stdin.readline().strip().split())

    ans = [0] * W
    for _ in range(H):
        C = input()
        for i, c in enumerate(C):
            if c == "#":
                ans[i] += 1

    ans = [str(i) for i in ans]
    print(" ".join(ans))

    return


if __name__ == "__main__":
    main()
