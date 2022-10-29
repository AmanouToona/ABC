import sys
import math

K = int(input())

# branch = ['7']
# for i in range(10 ** 6):
#     branch.append(branch[-1] + '7')
#
# ans = -1
#
# for i, b in enumerate(branch):
#     if int(b) % K == 0:
#         ans = i + 1
#         break
#
# print(ans)

k = 0

while k <= 10 ** 37:

    k += K
    print(k)
    if k < 7:
        continue

    if k % 7 == 0:
        print(int(math.log10(k)) + 1)
        sys.exit()

print(-1)
