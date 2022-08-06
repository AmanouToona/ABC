import sys


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A_bool = [a == i + 1 for i, a in enumerate(A)]

    ans = 0
    count = 0
    for b in A_bool:
        if not b:
            continue

        ans += count
        count += 1

    for i, b in enumerate(A_bool):
        if b:
            continue

        j = A[i]
        i += 1

        if j < i:
            continue

        ai = A[i - 1]
        aj = A[j - 1]

        if aj == i and ai == j:
            ans += 1

    print(ans)

    return


if __name__ == "__main__":
    main()
