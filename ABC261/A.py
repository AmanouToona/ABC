import sys


def main():
    L1, R1, L2, R2 = map(int, sys.stdin.readline().strip().split())

    if L1 > L2:
        L1, L2 = L2, L1
        R1, R2 = R2, R1

    if R1 <= L2:
        print(0)
        return

    if R1 >= R2:
        print(R2 - L2)
        return

    print(R1 - L2)

    return


if __name__ == "__main__":
    main()
