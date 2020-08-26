import sys

H, W, M = map(int, sys.stdin.readline().strip().split())

h = [0] * H
w = [0] * W

# g = [[False] * W for _ in range(H)]
S = set()
for _ in range(M):
    Th, Tw = map(int, sys.stdin.readline().strip().split())

    h[Th - 1] += 1
    w[Tw - 1] += 1

    # g[Th - 1][Tw - 1] = True
    S.add((Th - 1, Tw - 1))

max_h = max(h)
max_w = max(w)
ans = max_h + max_w

index_h = [n for n, v in enumerate(h) if v == max_h]
index_w = [n for n, v in enumerate(w) if v == max_w]

sub = 1
# for ih in index_h:
#     for iv in index_w:
#         if g[ih][iv] is False:
#             sub = 0
#             break
#     else:
#         continue
#     break
# ans -= sub
# print(ans)


for ih in index_h:
    for iv in index_w:
        if not (ih, iv) in S:
            print(ans)
            exit()
print(ans - 1)

