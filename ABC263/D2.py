import sys


def main():
    N, L, R = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    rev_A = list(reversed(A))

    a_sum = sum(A)
    changel = [a_sum]

    for l_pos in range(1, N + 1):
        changel.append(changel[-1] + L - A[l_pos - 1])

    for i in range(len(changel) - 1):
        changel[i + 1] = min(changel[i + 1], changel[i])

    changer = [a_sum]
    for r_pos in range(1, N + 1):
        changer.append(changer[-1] + R - rev_A[r_pos - 1])

    for i in range(len(changer) - 1):
        changer[i + 1] = min(changer[i + 1], changer[i])

    ans = a_sum
    for l_pos in range(N + 1):
        sub_l = a_sum - changel[l_pos]
        sub_r = a_sum - changer[N - l_pos]
        ans = min(ans, a_sum - sub_l - sub_r)

    print(ans)

    return


if __name__ == "__main__":
    main()
