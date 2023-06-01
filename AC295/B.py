import sys

sys.setrecursionlimit(10 ** 8)


def main():
    R, C = map(int, sys.stdin.readline().strip().split())

    B = []
    for _ in range(R):
        B.append(sys.stdin.readline())

    ans = []
    for r in range(R):
        _ans = []
        for c in range(C):
            if B[r][c] == "." or B[r][c] == "#":
                _ans.append(B[r][c])
            else:
                _ans.append(".")
        ans.append(_ans)

    for r in range(R):
        for c in range(C):
            if B[r][c] == "." or B[r][c] == "#":
                continue

            d = int(B[r][c])

            for dr in range(-d, d + 1):
                for dc in range(-d, d + 1):
                    if abs(dr) + abs(dc) > d:
                        continue

                    vr = r + dr
                    vc = c + dc

                    if vr >= R or vr < 0:
                        continue
                    if vc >= C or vc < 0:
                        continue

                    ans[vr][vc] = "."

    for a in ans:
        print("".join(a))

    return


if __name__ == "__main__":
    main()
