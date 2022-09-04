import sys

sys.setrecursionlimit(10 ** 8)


def main():
    S = input()

    line = [False] * 7  # 1本以上のピンが立っているか?

    if S[0] == "1":
        print("No")
        return

    for i, s in enumerate(S):
        if s == "0":
            continue

        j = i + 1

        if j == 7:
            line[0] = True
        elif j == 4:
            line[1] = True
        elif j == 8 or j == 2:
            line[2] = True
        elif j == 5 or j == 1:
            line[3] = True
        elif j == 9 or j == 3:
            line[4] = True
        elif j == 6:
            line[5] = True
        else:
            line[6] = True

    for left in range(5):
        if not line[left]:
            continue
        for right in range(left + 1, 7):
            if not line[right]:
                continue

            for mid in range(left + 1, right):
                if not line[mid]:
                    print("Yes")
                    return

    print("No")

    return


if __name__ == "__main__":
    main()
