import sys

sys.setrecursionlimit(10 ** 8)


def main():
    S = []
    for _ in range(10):
        S.append(sys.stdin.readline().strip())

    a = None
    b = None
    c = None
    d = None
    for h in range(10):
        for w in range(10):
            s = S[h][w]
            if s == ".":
                continue

            if a is None:
                a = h
            if c is None:
                c = w
            if b is None:
                b = h
            if d is None:
                d = w

            b = max(b, h)
            d = max(d, w)

    print(f"{a + 1} {b + 1}")
    print(f"{c + 1} {d + 1}")
    return


if __name__ == "__main__":
    main()
