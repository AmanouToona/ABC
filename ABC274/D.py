import sys

sys.setrecursionlimit(10**8)


def main():
    N, x, y = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    X = []
    Y = []
    for i, a in enumerate(A):
        if i % 2 == 0:
            X.append(a)
        else:
            Y.append(a)

    # x に到達可能か?
    setx = set([X[0]])
    for dx in X[1:]:
        set_ = set()
        for ux in setx:
            set_.add(ux + dx)
            set_.add(ux - dx)
        setx = set_

    if x not in setx:
        print("No")
        return

    # y に到達可能か?
    sety = set([0])
    for dy in Y:
        set_ = set()
        for uy in sety:
            set_.add(uy + dy)
            set_.add(uy - dy)
        sety = set_

    if y not in sety:
        print("No")
        return

    print("Yes")
    return


if __name__ == "__main__":
    main()
