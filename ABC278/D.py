import sys

sys.setrecursionlimit(10 ** 8)


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))
    Q = int(input())

    base = 0
    update_all = -1
    addition = dict()
    update_a = [-1] * len(A)
    for i, a in enumerate(A):
        addition[i] = a

    for q in range(Q):
        query = list(map(int, sys.stdin.readline().strip().split()))

        if query[0] == 1:
            base = query[1]
            update_all = q
        elif query[0] == 2:
            i = query[1] - 1
            if update_a[i] < update_all:
                addition[i] = query[2]
            else:
                addition[i] += query[2]
            update_a[i] = q
        else:
            i = query[1] - 1
            if update_a[i] < update_all:
                print(base)
            else:
                print(base + addition[i])

    return


if __name__ == "__main__":
    main()
