import sys
sys.setrecursionlimit(2 * 10 ** 5)

N, K = map(int, sys.stdin.readline().strip().split())
A = list(map(int, sys.stdin.readline().strip().split()))

town_line = []
town_set = set()
last_town = None


def search(town=0):
    global last_town
    if town not in town_set:
        town_line.append(town)
        town_set.add(town)
        search(town=A[town]-1)
    else:
        last_town = town
        return


search(0)
town_loop = town_line[town_line.index(last_town):]

if K < len(town_line):
    print(town_line[K] + 1)
else:
    k = K - len(town_line) + 1
    k = k % len(town_loop)
    print(town_loop[k - 1] + 1)
