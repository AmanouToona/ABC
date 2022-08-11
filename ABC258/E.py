import sys


def main():
    N, Q, X = map(int, sys.stdin.readline().strip().split())
    W = list(map(int, sys.stdin.readline().strip().split()))

    cum_w = [0]
    cum_w += W
    for i in range(len(cum_w) - 1):
        cum_w[i + 1] += cum_w[i]

    pos = 0
    nxt = [-1] * N
    while True:
        sum = X
        sum -= W[pos]

        if sum >= cum_w[N] - cum_w[pos]:
            sum -= cum_w[N] - cum_w[pos]
            pos = 0

        if sum >= cum_w[N]:
            sum %= cum_w[N]

        right = N
        left = pos
        while right - left > 1:
            mid = (right + left) // 2

            if cum_w[mid] - cum_w[pos] < sum:
                left = mid
            else:
                right = mid

        if nxt[right] != -1:
            break
        nxt[pos] = right % N
        pos = nxt[pos]

    for _ in range(Q):
        K = int(input())
    return


if __name__ == "__main__":
    main()
