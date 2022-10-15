import sys
from collections import defaultdict


sys.setrecursionlimit(10 ** 8)


def main():
    Q = int(sys.stdin.readline().strip())

    A = []
    note = defaultdict(list)
    ans = []
    pos = -1
    for _ in range(Q):
        q, *n = sys.stdin.readline().strip().split()
        if n:
            n = n[0]

        if q == "ADD":
            if pos + 1 < len(A):
                A[pos + 1] = n
            else:
                A.append(n)
            pos += 1
        elif q == "DELETE" and A:
            pos = max(-1, pos - 1)
        elif q == "SAVE":
            note[n] = A
        elif q == "LOAD":
            A = note[n]
            pos = len(A) - 1

        if pos >= 0:
            ans.append(A[pos])
        else:
            ans.append("-1")

    print(" ".join(ans))

    return


if __name__ == "__main__":
    main()
