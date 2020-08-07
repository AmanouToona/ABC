import sys

K = int(input())

count = 1
ans = -1
remainder = 0
check = [False] * (K + 1)

while True:
    remainder = (remainder * 10 + 7) % K
    if remainder == 0:
        ans = count
        break

    if check[remainder]:
        break

    check[remainder] = True
    count += 1

print(ans)
