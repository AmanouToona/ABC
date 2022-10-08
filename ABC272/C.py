import sys

sys.setrecursionlimit(10 ** 8)


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    ans = -1
    odd = []
    even = []
    for a in A:
        if a % 2 == 0:
            even.append(a)
        else:
            odd.append(a)

    even.sort()
    odd.sort()

    if len(even) >= 2:
        ans = max(ans, even[-1] + even[-2])
    if len(odd) >= 2:
        ans = max(ans, odd[-1] + odd[-2])

    print(ans)

    return


if __name__ == "__main__":
    main()
