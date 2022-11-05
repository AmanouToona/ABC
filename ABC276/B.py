import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    answer = [[] for _ in range(N + 1)]

    for _ in range(M):
        a, b = map(int, sys.stdin.readline().strip().split())

        answer[a].append(b)
        answer[b].append(a)

    for ans in answer[1:]:
        ans = list(set(ans))
        ans.sort()

        show = []
        show.append(len(ans))
        show.extend(ans)

        print(" ".join([str(i) for i in show]))

    return


if __name__ == "__main__":
    main()
