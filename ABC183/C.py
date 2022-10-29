import sys

sys.setrecursionlimit(10 ** 9)

N, K = map(int, sys.stdin.readline().strip().split())

T = []
for n in range(N):
    t = list(map(int, sys.stdin.readline().strip().split()))
    T.append(t)

footprint = [False] * N
footprint[0] = True
ans = []


def search(u, tot_time):
    footprint[u] = True
    # print(f'u: {u}, tot_time: {tot_time}, fp: {footprint}')

    if False not in footprint:
        ans.append(tot_time + T[u][0])
        footprint[u] = False
        return

    for v in range(1, N):
        if footprint[v] is False:
            search(v, tot_time + T[u][v])

    footprint[u] = False
    return


search(0, 0)

print(ans.count(K))
