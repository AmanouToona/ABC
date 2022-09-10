import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    P = list(map(int, sys.stdin.readline().strip().split()))

    p2pos = {}
    for i, p in enumerate(P):
        p2pos[p] = i

    happy = [0] * N

    for i in range(N):
        happy[(p2pos[i] - i) % N] += 1

    happy += happy

    ans = 0

    for i in range(len(happy) - 2):
        ans = max(ans, sum(happy[i : i + 3]))

    print(ans)

    return


if __name__ == "__main__":
    main()
