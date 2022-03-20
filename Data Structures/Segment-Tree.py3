from typing import List


class SegmentTree:
    n: int = 0
    t: List[int]

    def __init__(self, arr):
        self.n = len(arr)
        self.t = [0] * (self.n << 1)
        self.construct(arr, 1, 0, self.n - 1)

    def construct(self, arr, v=1, tl=0, tr=n - 1):
        if tl == tr:
            self.t[v] = arr[tl]
        else:
            tm = (tl + tr) >> 1
            self.construct(arr, v + 1, tl, tm)
            self.construct(arr, v + ((tm - tl + 1) << 1), tm + 1, tr)
            self.t[v] = self.t[v + 1] + self.t[v + ((tm - tl + 1) << 1)]

    def sum(self, *args):  # l r or v tl tr l r
        if len(args) == 2:
            return self.sum(1, 0, self.n - 1, args[0], args[1])
        v, tl, tr, left, right = args
        if left > right:
            return 0
        if left == tl and right == tr:
            return self.t[v]
        tm = (tl + tr) >> 1
        return self.sum(v + 1, tl, tm, left, min(right, tm)) + self.sum(v + ((tm - tl + 1) << 1), tm + 1, tr,
                                                                        max(left, tm + 1), right)

    def update(self, *args):  # pos val or v tl tr pos val
        if len(args) == 2:
            return self.update(1, 0, self.n - 1, args[0], args[1])
        v, tl, tr, pos, val = args
        if tl == tr:
            self.t[v] = val
        else:
            tm = (tl + tr) >> 1
            if pos <= tm:
                self.update(v + 1, tl, tm, pos, val)
            else:
                self.update(v + ((tm - tl + 1) << 1), tm + 1, tr, pos, val)
            self.t[v] = self.t[v + 1] + self.t[v + ((tm - tl + 1) << 1)]


seg = SegmentTree([1, 2, 3, 4, 5])
for i in range(5):
    for j in range(i, 5):
        print(i, j, seg.sum(i, j))
