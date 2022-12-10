import sys
import re

sys.setrecursionlimit(10 ** 8)


def main():
    S = input().strip()

    m = re.match(r"[A-Z]\d{6}[A-Z]", S)

    if not m:
        print("No")
        return

    num = int(S[1:-1])

    # if S[0].isnumeric():
    #     print("No")
    #     return

    # try:
    #     num = int(S[1:-1])
    # except:
    #     print("No")
    #     return

    if num < 100000 or num > 999999:
        print("No")
        return

    print("Yes")

    # if S[-1].isnumeric():
    #     print("No")
    #     return

    # print("Yes")

    return


if __name__ == "__main__":
    main()
