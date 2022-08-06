import sys


def main():
    N, L, R = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    # 置き換えないパターン
    a_sum = sum(A)

    # 全部 L パターン
    ans = min(a_sum, L * N)

    # 全部 R パターン
    ans = min(ans, R * N)

    # L, R で置き換えるパターン
    back_cusum = A.copy()
    for i in range(N - 1, 0, -1):
        back_cusum[i - 1] += back_cusum[i]

    # L で置き換える
    changed_l = [a_sum]
    for l_pos in range(1, N + 1):
        changed_l.append(changed_l[-1] + L - A[l_pos - 1])

    left_pos = 0
    changed_l_min = changed_l[0]
    for i, val in enumerate(changed_l):
        if val < changed_l_min:
            left_pos = i
        changed_l_min = min(changed_l_min, val)

    Led_A = A.copy()
    for i in range(left_pos):
        Led_A[i] = L

    # R で置き換える
    Led_A = list(reversed(Led_A))
    changed_r = [sum(Led_A)]
    for r_pos in range(1, N + 1):
        changed_r.append(changed_r[-1] + R - Led_A[r_pos - 1])

    ans = min(ans, min(changed_r))

    print(ans)

    return


if __name__ == "__main__":
    main()
