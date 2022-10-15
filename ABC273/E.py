import sys
from collections import defaultdict


sys.setrecursionlimit(10 ** 8)


class Node:
    def __init__(self, val, prev=None) -> None:
        self.val = val
        self.prev = prev


class Tree:
    def __init__(self) -> None:
        self.root = Node("-1")
        self.now = self.root

    def add(self, val):
        new = Node(val, self.now)
        self.now = new
        return

    def delete(self):
        if self.now.prev:
            self.now = self.now.prev
        return

    def get_pos(self):
        return self.now

    def load(self, new):
        self.now = new
        return

    def get_tail(self):
        return self.now.val

    def get_root(self):
        return self.root


def main():
    Q = int(sys.stdin.readline().strip())

    tree = Tree()
    ans = []
    note = defaultdict(tree.get_root)
    for _ in range(Q):
        q = sys.stdin.readline().strip().split()

        if len(q) == 2:
            n = q[1]

        q = q[0]

        if q == "ADD":
            tree.add(n)
        elif q == "DELETE":
            tree.delete()
        elif q == "SAVE":
            note[n] = tree.get_pos()
        elif q == "LOAD":
            tree.load(note[n])

        ans.append(tree.get_tail())

    print(" ".join(ans))

    return


if __name__ == "__main__":
    main()
