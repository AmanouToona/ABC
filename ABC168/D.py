import sys
import heapq

N, M = map(int, sys.stdin.readline().strip().split())
G = [[] for _ in range(N)]
for m in range(M):
    a, b = map(int, sys.stdin.readline().strip().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

# print(G)
# みんな大好き　ダイクストラ
d = [] * N
c = [False] * N
heapq.heappush(d, (0, 0))
p = [N] * N  # 親を保存するリスト　親ノードとしてあり得ない N を初期値にした

mindist = [float('inf')] * N
mindist[0] = 0

while d:
    now = heapq.heappop(d)[1]
    c[now] = True

    for i in G[now]:
        if mindist[now] + 1 < mindist[i]:
            mindist[i] = mindist[now] + 1
            p[i] = now
            heapq.heappush(d, (mindist[i], i))

# print(p)
# 答える
if N in set(p[1:]):
    print('No')
else:
    print('Yes')
    for i in p[1:]:
        print(i + 1)


