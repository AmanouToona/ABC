import sys

sys.setrecursionlimit(10**8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    S = []
    T = []
    for _ in range(N - 1):
        s, t = map(int, sys.stdin.readline().strip().split())
        S.append(s)
        T.append(t)

    for i in range(N - 1):
        v = A[i] // S[i] * T[i]
        A[i + 1] += v

    print(A[-1])

    return


if __name__ == "__main__":
    main()
