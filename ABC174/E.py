import sys
import math

N, K = map(int, sys.stdin.readline().strip().split())
A = list(map(int, sys.stdin.readline().strip().split()))

left = 0  # 出来ない長さ
right = 10 ** 9 + 1  # 出来る長さ


def judge(length, num_cut):
    cut = 0
    for a in A:
        if a > length:
            cut += math.ceil(a / length) - 1

    if cut <= num_cut:
        return True

    return False


while right - left > 1:
    mid = (left + right) // 2
    # print(f'right: {right}, left: {left}, mid: {mid}')

    if judge(mid, K):
        right = mid
    else:
        left = mid

print(right)
