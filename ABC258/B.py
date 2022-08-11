import sys


def main():
    N = int(input())

    A = []

    for _ in range(N):
        a = sys.stdin.readline().strip()
        A.append(a)

    # loop start position
    dh = [0, 1, 1, 1, 0, -1, -1, -1]
    dw = [1, 1, 0, -1, -1, -1, 0, 1]

    ans = -float("inf")
    for h in range(N):
        for w in range(N):
            for direction in range(8):
                _sum = 0
                for i in range(N):
                    h_now = h + dh[direction] * i
                    h_now += N
                    h_now %= N

                    w_now = w + dw[direction] * i
                    w_now += N
                    w_now %= N

                    _sum += int(A[h_now][w_now]) * 10 ** (N - 1 - i)

                ans = max(ans, _sum)

    print(ans)


if __name__ == "__main__":
    main()
