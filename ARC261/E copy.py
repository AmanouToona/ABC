import sys


def main():
    N, C = map(int, sys.stdin.readline().strip().split())

    # 1つ前の演算までを終えた状態
    p0 = 0
    p1 = 1

    X = C
    for _ in range(N):
        T, A = map(int, sys.stdin.readline().strip().split())

        x = X
        temp = 0
        while x > 0:
            temp <<= 1
            if x & 1 == 1:
                if p1:
                    temp += 1
            else:
                if p0:
                    temp += 1
            x >>= 1

        temp2 = 0
        while temp > 0:
            temp <<= 1
            if temp & 1 == 1:
                temp2 += 1
            temp >>= 1

        if T == 1:  # and
            p0 &= A
            p0 &= 1
            p1 &= A
            p1 &= 1
            X &= A
        elif T == 2:  # or
            p0 |= A
            p0 |= 1
            p1 |= A
            p1 |= 1
            X |= A
        else:  # xor
            p0 ^= A
            p0 ^= 1
            p1 ^= A
            p1 ^= 1
            X ^= A

        print(X)

    return


if __name__ == "__main__":
    main()
