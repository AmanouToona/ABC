import sys
import heapq

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    node_cost = [0] * N

    G = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)

        node_cost[u] += A[v]
        node_cost[v] += A[u]

    q = []
    heapq.heapify(q)

    for p in range(N):
        cost = 0
        for child in G[p]:
            cost += A[child]

        heapq.heappush(q, (cost, p))

    droped = [False] * N

    n = N
    max_cost = -float("inf")
    while n > 0:
        cost, p = heapq.heappop(q)
        if droped[p]:
            continue

        droped[p] = True
        n -= 1

        max_cost = max(max_cost, cost)

        for child in G[p]:
            if droped[child]:
                continue
            node_cost[child] -= A[p]
            heapq.heappush(q, (node_cost[child], child))

    print(max_cost)
    return


if __name__ == "__main__":
    main()
