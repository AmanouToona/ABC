import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A = [i - 1 for i in A]

    B = [i for i in range(N)]
    pos = {i: i for i in range(N)}

    nums = []  # 操作 i の手前での 0 の位置

    for a in A:
        val1 = B[a]
        val2 = B[a + 1]

        B[a], B[a + 1] = B[a + 1], B[a]

        nums.append(B[pos[0]])

        pos[val1] = a + 1
        pos[val2] = a

    for num in nums:
        print(pos[num] + 1)

    return


if __name__ == "__main__":
    main()
