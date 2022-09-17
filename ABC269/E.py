import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    a = 0
    b = N

    while b - a > 1:
        mid = (b + a) // 2

        print(f"? {mid + 1} {b} 1 {N}")

        T = int(input())

        if T == b - mid:
            b = mid
        else:
            a = mid

    c = 0
    d = N

    while d - c > 1:
        mid = (d + c) // 2

        print(f"? 1 {N} {mid + 1} {d} ")

        T = int(input())

        if T == d - mid:
            d = mid
        else:
            c = mid

    print(f"! {b} {d}")

    return


if __name__ == "__main__":
    main()
