import sys

N = int(input())
c = list(str(input()))

left = [-1, False]  # 一番左の W　を記録
right = [len(c), False]  # 一番右の R を記録
count = 0

for i in range(len(c)):
    if not left[1]:
        left[0] += 1
        if c[left[0]] == 'W':
            left[1] = True

    if not right[1]:
        right[0] -= 1
        if c[right[0]] == 'R':
            right[1] = True

    if left[1] and right[1]:
        if left[0] > right[0]:
            break
        count += 1
        left[1] = False
        right[1] = False

    # if c[i] == 'W':
    #     left = i
    # if c[len(c) - 1 - i] == 'R':
    #     right = len(c) - 1 - i
    #
    # if (left is not None) and (right is not None) and (left < right):
    #     # print(f'left{left}, right {right}')
    #     count += 1
    #     left = None
    #     right = None

print(count)

