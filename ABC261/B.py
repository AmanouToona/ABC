import sys


def main():
    N = int(input())
    A = []
    for _ in range(N):
        A.append(sys.stdin.readline())

    for i in range(N):
        for j in range(N):
            if i == j:
                continue

            if A[i][j] == "D" or A[j][i] == "D":
                if A[i][j] != "D" or A[j][i] != "D":
                    print("incorrect")
                    return
                continue

            if A[i][j] == "W" and A[j][i] == "L":
                continue
            if A[i][j] == "L" and A[j][i] == "W":
                continue

            print("incorrect")
            return

    print("correct")

    return


if __name__ == "__main__":
    main()
