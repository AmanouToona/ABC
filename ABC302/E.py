import sys

sys.setrecursionlimit(10**8)


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())

    node = [set() for _ in range(N)]
    ans = N

    for _ in range(Q):
        query = tuple(sys.stdin.readline().strip().split())

        if len(query) == 3:
            _, u, v = query
            u = int(u)
            v = int(v)
            u -= 1
            v -= 1
            if len(node[u]) == 0:
                ans -= 1
            if len(node[v]) == 0:
                ans -= 1

            node[u].add(v)
            node[v].add(u)

        else:
            _, v = query
            v = int(v)
            v -= 1

            for u in node[v]:
                node[u].remove(v)
                if len(node[u]) == 0:
                    ans += 1

            if len(node[v]) != 0:
                ans += 1
                node[v] = set()

        print(ans)

    return


if __name__ == "__main__":
    main()
