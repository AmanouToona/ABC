import sys

sys.setrecursionlimit(10 ** 8)


def disassemble(n):
    res = [n, 0, 0]

    while res[0] % 2 == 0:
        res[0] //= 2
        res[1] += 1

    while res[0] % 3 == 0:
        res[0] //= 3
        res[2] += 1

    return res


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    dis = []
    for a in A:
        dis.append(disassemble(a))

    root = dis[0][0]
    div2 = float("inf")
    div3 = float("inf")
    for d in dis:
        if d[0] != root:
            print(-1)
            return

        if d[1] < div2:
            div2 = d[1]

        if d[2] < div3:
            div3 = d[2]

    ans = 0
    for d in dis:
        ans += d[1] - div2
        ans += d[2] - div3

    print(ans)
    return


if __name__ == "__main__":
    main()
