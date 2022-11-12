import sys
from collections import defaultdict
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    ladder = defaultdict(list)
    for _ in range(N):
        a, b = map(int, sys.stdin.readline().strip().split())
        ladder[a].append(b)
        ladder[b].append(a)

    used = set()
    q = deque()
    ans = 1

    used.add(1)
    q.append(1)

    while q:
        u = q.popleft()

        for v in ladder[u]:
            if v in used:
                continue
            q.append(v)
            ans = max(ans, v)
            used.add(v)

    print(ans)

    return


if __name__ == "__main__":
    main()
