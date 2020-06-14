import sys

N, M, X = map(int, sys.stdin.readline().strip().split())

C = []
A = []
for _ in range(N):
    c, *a = map(int, sys.stdin.readline().strip().split())
    C.append(c)
    A.append(a)

ans = float('inf')

for i in range(2 ** N):
    bit = [(i >> j) & 1 for j in range(N)]  # 本を購入するかしないか

    understand = [0] * M
    for i, b in enumerate(bit):
        if b != 0:
            # print(f'i: {i}, lenA: {len(A)}, len under: {len(understand)}')
            understand = [x + y for x, y in zip(A[i], understand)]

    if min(understand) >= X:
        cost = [c * b for c, b in zip(C, bit)]
        ans = min(sum(cost), ans)

if ans == float('inf'):
    print(-1)
else:
    print(ans)
