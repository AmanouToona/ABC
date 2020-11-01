import sys
sys.setrecursionlimit(10 ** 9)


S = str(sys.stdin.readline().strip())

bucket = [0] * 9
for s in S:
    bucket[int(s) - 1] += 1

for i in range(1, 1000):
    can_make = True
    if i % 8 != 0:
        continue
    if i <= 99 and len(S) >=3:
        continue
    if i <= 9 and len(S) >= 2:
        continue

    mini_bucket = [0] * 9
    for j in str(i):
        if j == '0':
            can_make = False
            break
        mini_bucket[int(j) - 1] += 1

    if sum(mini_bucket) == 0:
        continue

    for k in range(9):
        if bucket[k] < mini_bucket[k]:
            can_make = False
            break

    if can_make:
        print('Yes')
        sys.exit()

print('No')
