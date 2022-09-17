import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    bit = []
    for i in range(61):  # 60でいいと思うけど念のため
        if (N >> i) & 1:
            bit.append(i)

    bit = list(reversed(bit))

    answers = []
    for i in range(1 << len(bit)):
        ans = 0
        for b in range(len(bit)):
            if (i >> b) & 1:
                ans += 2 ** bit[b]

        answers.append(ans)

    answers.sort()
    for a in answers:
        print(a)
    return


if __name__ == "__main__":
    main()
