import sys
from collections import defaultdict


def main():
    N = int(input())

    A = []
    for _ in range(N):
        m = int(sys.stdin.readline().strip())

        a = []
        for _ in range(m):
            p, e = map(int, sys.stdin.readline().strip().split())
            a.append((p, e))
        A.append(a)

    # 各 p について eの最大をまとめる
    max_p_e = defaultdict(int)
    for a in A:
        for p, e in a:
            max_p_e[p] = max(max_p_e[p], e)

    # 各a が max p e を単独で持っているか?
    max_e_count = defaultdict(int)
    for a in A:
        for p, e in a:
            if max_p_e[p] != e:
                continue
            max_e_count[p] += 1

    ans = 0
    for a in A:
        for p, e in a:
            if max_p_e[p] != e:
                continue
            if max_e_count[p] != 1:
                continue
            ans += 1
            break

    if ans < N:
        ans += 1

    print(ans)

    return


if __name__ == "__main__":
    main()
