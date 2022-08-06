import sys
from collections import deque


def main():
    N = int(input())

    xyp = []
    for _ in range(N):
        x, y, P = map(int, sys.stdin.readline().strip().split())
        xyp.append((x, y, P))

    def reach(from_, train):
        q = deque([])

        used = [False] * N
        used[from_] = True
        q.append(from_)

        while q:
            u = q.popleft()

            for i in range(N):
                if used[i]:
                    continue

                ux, uy, p = xyp[u]
                vx, vy, _ = xyp[i]

                if train * p < abs(ux - vx) + abs(uy - vy):
                    continue

                used[i] = True
                q.append(i)

        return all(used)

    left = 0
    right = 4 * 10 ** 9 + 1
    while right - left > 1:
        mid = (right + left) // 2

        for start in range(N):
            if reach(start, mid):
                right = mid
                break

        if right == mid:
            continue

        left = mid

    print(right)

    return


if __name__ == "__main__":
    main()
