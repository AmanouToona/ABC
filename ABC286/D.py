import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, X = map(int, sys.stdin.readline().strip().split())

    A = []
    B = []
    for _ in range(N):
        a, b = map(int, sys.stdin.readline().strip().split())
        A.append(a)
        B.append(b)

    can = {0}
    for i in range(N):
        a, b = A[i], B[i]

        can_ = set()
        for i in range(b + 1):
            for c in can:
                new = c + a * i

                if new > X:
                    continue

                can_.add(new)

        can = can_

    if X in can:
        print("Yes")
    else:
        print("No")

    return


if __name__ == "__main__":
    main()
