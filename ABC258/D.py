import sys


def main():
    N, X = map(int, sys.stdin.readline().strip().split())

    ab = []
    for _ in range(N):
        A, B = map(int, sys.stdin.readline().strip().split())
        ab.append((A, B))

    cum = [0]
    b_min = [float("inf")]
    for i in range(1, N + 1):
        a, b = ab[i - 1]
        cum.append(cum[-1] + a + b)
        b_min.append(min(b, b_min[-1]))

    ans = float("inf")
    for i in range(1, min(N, X) + 1):
        _ans = cum[i] + b_min[i] * (X - i)
        ans = min(ans, _ans)

    print(ans)


if __name__ == "__main__":
    main()
