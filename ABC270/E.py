import sys

sys.setrecursionlimit(10**8)


def main():
    N, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    b = [(a, i) for i, a in enumerate(A)]

    A.sort()

    i = 0
    cycle = 0
    while K > 0:
        r = 0
        if i > 0:
            r = A[i - 1]

        if K < N * (A[i] - r):
            cycle += K // N
            K -= (K // N) * N

            break

        if A[i] - r:
            i += 1
            continue

        K -= N * (A[i] - r)
        cycle = A[i]
        N -= 1
        i += 1

    ans = [0] * len(b)
    for val, key in b:
        ans[key] = val

    for i in range(N):
        if ans[i] < cycle:
            ans[i] = 0
            continue
        ans[i] -= cycle
        if K > 0 and ans[i] > 0:
            ans[i] -= 1
            K -= 1

    ans = [f"{a}" for a in ans]
    ans = " ".join(ans)
    print(ans)
    return


if __name__ == "__main__":
    main()
