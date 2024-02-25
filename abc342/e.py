import heapq
import sys

sys.setrecursionlimit(10**8)

no = "Unreachable"


def get_max(max_time, info):
    # max_time に B に到着する電車について、最も遅いAの出発時刻
    m = (max_time - info[0] - info[3]) // info[1]
    m = min(info[2] - 1, m)

    if m < 0:
        return -1

    return info[0] + info[1] * m


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    path = [[] for _ in range(N)]
    for _ in range(M):
        l, d, k, c, A, B = map(int, sys.stdin.readline().strip().split())
        A -= 1
        B -= 1

        path[B].append((l, d, k, c, A))

    ans = [-1] * N
    q = []
    heapq.heappush(q, (-(10**36), N - 1))

    while q:
        t, v = heapq.heappop(q)
        t *= -1

        for info in path[v]:
            u = info[-1]
            t_u = get_max(t, info=info)

            if ans[u] >= t_u:
                continue

            ans[u] = t_u
            heapq.heappush(q, (-1 * t_u, u))

    for a in ans[:-1]:
        if a != -1:
            print(a)
        else:
            print(no)

    return


if __name__ == "__main__":
    main()
