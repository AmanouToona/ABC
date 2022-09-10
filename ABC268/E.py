import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    P = list(map(int, sys.stdin.readline().strip().split()))

    unhappy = 0
    for i, p in enumerate(P):
        unhappy += (N - (i - p) % N) % N

    p2pos = {}
    for i, p in enumerate(P):
        p2pos[p] = i

    dist = [0] * N
    for i in range(N):
        dist[(p2pos[i] - i) % N] += 1

    half = (N + 1) // 2
    diff = 0
    for i in range(N):
        if i < half:
            diff += 1
        else:
            diff -= 1

    ans = unhappy
    for i in range(N):
        unhappy += diff
        ans = min(ans, unhappy)

        diff += diff[i]
        diff -= diff[(i + half) % N]

    print(ans)

    return


if __name__ == "__main__":
    main()
