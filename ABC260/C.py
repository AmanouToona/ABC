import sys


def main():
    S = str(input())
    T = str(input())

    if len(S) > len(T):
        print("No")
        return

    i = 0
    for t in T:
        if i >= len(S):
            if S[i - 2] == S[i - 1] and S[i - 1] == t:
                continue
            else:
                print("No")
                return

        if S[i] == t:
            i += 1
            continue
        if i < 1:
            print("No")
            return

        if S[i - 2] == S[i - 1] and S[i - 1] == t:
            continue
        else:
            print("No")
            return
    print("Yes")
    return


if __name__ == "__main__":
    main()
