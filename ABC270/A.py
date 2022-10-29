import sys

sys.setrecursionlimit(10 ** 8)


def main():
    A, B = map(int, sys.stdin.readline().strip().split())

    a_421 = [False] * 3
    b_421 = [False] * 3

    for i, p in enumerate([4, 2, 1]):
        if A >= p:
            a_421[i] = True
            A -= p

    for i, p in enumerate([4, 2, 1]):
        if B >= p:
            b_421[i] = True
            B -= p

    ans = 0
    for i, p in enumerate([4, 2, 1]):
        if a_421[i] or b_421[i]:
            ans += p

    print(ans)
    return


if __name__ == "__main__":
    main()
