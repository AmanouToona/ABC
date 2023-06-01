# trie木 version

import sys

# 参考: https://rightcode.co.jp/blog/information-technology/trie-fast-dictionary-implementation-1


class Node:
    def __init__(self, item=None) -> None:
        self.children = {}
        self.itme = item
        return


class Trie:
    def __init__(self) -> None:
        root = Node()
        self.nodes = [root]
        return

    def __add_node(self, node):
        self.nodes.append(node)
        return len(self.nodes) - 1

    def __get_char_num(self, c):
        return ord(c) - ord("a")

    def insert(self, word, item, char_index=0, node_index=0):
        char_num = self.__get_char_num(word[char_index])
        next_node_index = self.nodes[node_index].children[char_num]
        return


def main():
    N = int(input())

    S = []
    for _ in range(N):
        S.append(sys.stdin.readline().strip())

    return


if __name__ == "__main__":
    main()
