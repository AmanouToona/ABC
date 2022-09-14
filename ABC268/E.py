import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    P = list(map(int, sys.stdin.readline().strip().split()))

    p2pos = {}
    for i, p in enumerate(P):
        p2pos[p] = i

    # 現在の不満度を記録する
    unhappy = 0
    for i in range(N):
        dist = (i - p2pos[i]) % N
        unhappy += min(N - dist, dist)

    # 不満度正負の変化点と現在の不満度の変化を記録する
    delta = 0
    e = [0] * (N)
    for i in range(N):
        d = (p2pos[i] - i) % N
        if d < N // 2:
            delta += 1
        elif d >= (N + 1) // 2:
            delta -= 1

        e[(N - d) % N] += 2
        e[(N - d + N // 2) % N] -= 1
        e[(N - d + (N + 1) // 2) % N] -= 1

    ans = unhappy
    for i in range(1, N):
        unhappy += delta
        delta += e[i]
        ans = min(ans, unhappy)

    print(ans)

    return


if __name__ == "__main__":
    main()
