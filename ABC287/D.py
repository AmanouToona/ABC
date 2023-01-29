import sys

sys.setrecursionlimit(10 ** 8)


def main():
    S = input()
    T = input()

    no = 0
    for i, s in enumerate(S[-len(T) :]):
        if s == "?":
            continue
        if T[i] == "?":
            continue
        if T[i] != s:
            no += 1

    if no == 0:
        print("Yes")
    else:
        print("No")

    for x in range(len(T)):
        # 加える
        s = S[x]
        t = T[x]

        if s != "?" and t != "?" and s != t:
            no += 1

        # 外す
        num = len(T) - x
        s = S[-num]
        t = T[x]

        if s != "?" and t != "?" and s != t:
            no -= 1

        if no == 0:
            print("Yes")
        else:
            print("No")

    return


if __name__ == "__main__":
    main()
