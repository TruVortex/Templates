from typing import List


class FenwickTree:

    bit: List[int]

    def __init__(self, n):
        self.bit = [0] * (n + 1)

    @staticmethod
    def parent(n):
        return n - (n & (-n))

    @staticmethod
    def next(n):
        return n + (n & (-n))

    def get_num(self, n):
        return self.get_sum(n) - self.get_sum(n - 1)

    def get_sum(self, *args):  # r or l r
        if len(args) == 1:
            n = args[0] + 1
            tot = 0
            while n > 0:
                tot += self.bit[n]
                n = self.parent(n)
            return tot
        return self.get_sum(args[1]) - self.get_sum(args[0] - 1)

    def update(self, n, x):
        n += 1
        while n < len(self.bit):
            self.bit[n] += x
            n = self.next(n)

    def set(self, n, x):
        self.update(n, x - self.get_num(n))


ft = FenwickTree(5)
ft.update(0, 1)
ft.update(1, 5)
ft.update(2, 3)
ft.update(3, 4)
ft.update(4, 5)
print(ft.get_num(2))
ft.set(2, 4)
print(ft.get_num(2))
print(ft.get_sum(3))
print(ft.get_sum(1, 3))
