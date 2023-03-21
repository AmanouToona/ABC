import sys
from collections import defaultdict

import math
from bisect import bisect_left, bisect_right
from typing import Generic, Iterable, Iterator, TypeVar, Union, List

T = TypeVar("T")


class SortedSet(Generic[T]):
    BUCKET_RATIO = 50
    REBUILD_RATIO = 170

    def __init__(self, a: Iterable[T] = []) -> None:
        "Make a new SortedSet from iterable. / O(N) if sorted and unique / O(N log N)"
        a = list(a)
        if not all(a[i] < a[i + 1] for i in range(len(a) - 1)):
            a = sorted(set(a))
        self._build(a)

    def _build(self, a=None) -> None:
        "Evenly divide `a` into buckets."
        if a is None:
            a = list(self)
        size = self.size = len(a)
        bucket_size = int(math.ceil(math.sqrt(size / self.BUCKET_RATIO)))
        self.a = [a[size * i // bucket_size : size * (i + 1) // bucket_size] for i in range(bucket_size)]

    def __iter__(self) -> Iterator[T]:
        for i in self.a:
            for j in i:
                yield j

    def __reversed__(self) -> Iterator[T]:
        for i in reversed(self.a):
            for j in reversed(i):
                yield j

    def __len__(self) -> int:
        return self.size

    def __repr__(self) -> str:
        return "SortedSet" + str(self.a)

    def __str__(self) -> str:
        s = str(list(self))
        return "{" + s[1 : len(s) - 1] + "}"

    def _find_bucket(self, x: T) -> List[T]:
        "Find the bucket which should contain x. self must not be empty."
        for a in self.a:
            if x <= a[-1]:
                return a
        return a

    def __contains__(self, x: T) -> bool:
        if self.size == 0:
            return False
        a = self._find_bucket(x)
        i = bisect_left(a, x)
        return i != len(a) and a[i] == x

    def add(self, x: T) -> bool:
        "Add an element and return True if added. / O(√N)"
        if self.size == 0:
            self.a = [[x]]
            self.size = 1
            return True
        a = self._find_bucket(x)
        i = bisect_left(a, x)
        if i != len(a) and a[i] == x:
            return False
        a.insert(i, x)
        self.size += 1
        if len(a) > len(self.a) * self.REBUILD_RATIO:
            self._build()
        return True

    def discard(self, x: T) -> bool:
        "Remove an element and return True if removed. / O(√N)"
        if self.size == 0:
            return False
        a = self._find_bucket(x)
        i = bisect_left(a, x)
        if i == len(a) or a[i] != x:
            return False
        a.pop(i)
        self.size -= 1
        if len(a) == 0:
            self._build()
        return True

    def lt(self, x: T) -> Union[T, None]:
        "Find the largest element < x, or None if it doesn't exist."
        for a in reversed(self.a):
            if a[0] < x:
                return a[bisect_left(a, x) - 1]

    def le(self, x: T) -> Union[T, None]:
        "Find the largest element <= x, or None if it doesn't exist."
        for a in reversed(self.a):
            if a[0] <= x:
                return a[bisect_right(a, x) - 1]

    def gt(self, x: T) -> Union[T, None]:
        "Find the smallest element > x, or None if it doesn't exist."
        for a in self.a:
            if a[-1] > x:
                return a[bisect_right(a, x)]

    def ge(self, x: T) -> Union[T, None]:
        "Find the smallest element >= x, or None if it doesn't exist."
        for a in self.a:
            if a[-1] >= x:
                return a[bisect_left(a, x)]

    def __getitem__(self, x: int) -> T:
        "Return the x-th element, or IndexError if it doesn't exist."
        if x < 0:
            x += self.size
        if x < 0:
            raise IndexError
        for a in self.a:
            if x < len(a):
                return a[x]
            x -= len(a)
        raise IndexError

    def index(self, x: T) -> int:
        "Count the number of elements < x."
        ans = 0
        for a in self.a:
            if a[-1] >= x:
                return ans + bisect_left(a, x)
            ans += len(a)
        return ans

    def index_right(self, x: T) -> int:
        "Count the number of elements <= x."
        ans = 0
        for a in self.a:
            if a[-1] > x:
                return ans + bisect_right(a, x)
            ans += len(a)
        return ans


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    maxa = max(A)

    canuse = SortedSet()
    canuse_cnt = defaultdict(int)
    using = SortedSet()
    using_cnt = defaultdict(int)

    for a in A[:M]:
        canuse.add(a)
        canuse_cnt[a] += 1

    tot = 0
    for _ in range(K):
        b = canuse.gt(0)
        tot += b
        using.add(b)
        using_cnt[b] += 1

        canuse_cnt[b] -= 1
        if canuse_cnt[b] == 0:
            canuse.discard(b)

    ans = []
    ans.append(tot)
    cnt = K

    for i, a in enumerate(A[M:]):
        _a = A[i]
        if canuse_cnt[_a] > 0:
            canuse.discard(_a)
            canuse_cnt[_a] -= 1
        else:
            using_cnt[_a] -= 1
            if using_cnt[_a] == 0:
                using.discard(_a)
            tot -= _a
            cnt -= 1

        canuse.add(a)
        canuse_cnt[a] += 1

        if cnt < K:
            b = canuse.gt(0)
            tot += b
            using.add(b)
            using_cnt[b] += 1

            canuse_cnt[b] -= 1
            if canuse_cnt[b] == 0:
                canuse.discard(b)
            cnt += 1

        max_use = using.le(maxa)

        if canuse.gt(0) and max_use > canuse.gt(0):
            using_cnt[max_use] -= 1

            canuse.add(max_use)
            canuse_cnt[max_use] += 1

            if using_cnt[max_use] == 0:
                using.discard(max_use)
            tot -= max_use

            b = canuse.gt(0)
            tot += b
            using.add(b)
            using_cnt[b] += 1

            canuse_cnt[b] -= 1
            if canuse_cnt[b] == 0:
                canuse.discard(b)

        ans.append(tot)

    print(*ans)

    return


if __name__ == "__main__":
    main()