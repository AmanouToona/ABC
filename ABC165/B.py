from math import log
from math import ceil

x = int(input())

left = 1
right = 3760

# にぶたん
while right - left != 1:
    mid = (right + left) // 2
    money = 100
    for i in range(mid):
        money = int(money * 1.01)
    if money >= x:
        right = mid
    else:
        left = mid
print(right)
