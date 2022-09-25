import sys

sys.setrecursionlimit(10**8)


def main():
    _, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    left = 0
    right = 10**12 + 1

    while right - left > 1:
        mid = (right + left) // 2

        sum_a = 0
        for a in A:
            if a <= mid:
                sum_a += a
            else:
                sum_a += mid

        if sum_a >= K:
            right = mid
        else:
            left = mid

    ans = []
    tot = 0
    for a in A:
        if a < left:
            ans.append(0)
            tot += a
        else:
            ans.append(a - left)
            tot += left

    for i, a in enumerate(ans):
        if a == 0:
            continue

        if a > 0:
            ans[i] -= 1
            tot += 1

        if tot == K:
            break

    ans = [f"{a}" for a in ans]
    ans = " ".join(ans)
    print(ans)

    return


if __name__ == "__main__":
    main()
