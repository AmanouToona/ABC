import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    W = list(sys.stdin.readline().strip().split())

    pattern = set(["and", "not", "that", "the", "you"])
    for w in W:
        if w in pattern:
            print("Yes")
            return

    print("No")

    return


if __name__ == "__main__":
    main()
