import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    called = [False] * N
    for i, a in enumerate(A):
        if called[i]:
            continue
        called[a - 1] = True

    ans = []
    for i, t in enumerate(called):
        if t:
            continue
        ans.append(i + 1)

    print(len(ans))
    print(*ans)

    return


if __name__ == "__main__":
    main()
