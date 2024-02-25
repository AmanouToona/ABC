import sys

sys.setrecursionlimit(10**8)


def main():
    N = int(input())
    S = input().strip()
    Q = int(input())

    az = [chr(ord("a") + i) for i in range(26)]
    for _ in range(Q):
        c, d = map(str, sys.stdin.readline().strip().split())

        for i, s in enumerate(az):
            if s == c:
                az[i] = d

    ans = []
    for s in S:
        pos = ord(s) - ord("a")
        ans.append(az[pos])

    print("".join(ans))

    return


if __name__ == "__main__":
    main()
