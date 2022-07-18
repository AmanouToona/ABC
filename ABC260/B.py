import sys


def main():
    N, X, Y, Z = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    B = list(map(int, sys.stdin.readline().strip().split()))

    cand = []
    for i, (a, b) in enumerate(zip(A, B)):
        cand.append((i, -a, -b))

    cand.sort(key=lambda x: x[1])

    passed = []
    for x in range(X):
        passed.append(cand[x][0])

    cand = cand[X:]
    cand.sort(key=lambda x: x[0])
    cand.sort(key=lambda x: x[2])
    for y in range(Y):
        passed.append(cand[y][0])

    cand = cand[Y:]
    cand.sort(key=lambda x: x[0])
    cand.sort(key=lambda x: x[1] + x[2])
    for z in range(Z):
        passed.append(cand[z][0])

    passed.sort()
    passed = [i + 1 for i in passed]

    for p in passed:
        print(p)

    return


if __name__ == "__main__":
    main()
