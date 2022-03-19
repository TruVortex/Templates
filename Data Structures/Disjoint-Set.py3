import sys
import functools

from typing import List

sys.setrecursionlimit(100000)

class Edge:

    def __init__(self, a=-1, b=-1, weight=-1):
        self.a = a
        self.b = b
        self.weight = weight


class DisjointSet:
    edges: List[Edge] = []
    parent: List[int] = []
    rank: List[int] = []

    def __init__(self, v):
        for i in range(v):
            self.parent.append(i)
            self.rank.append(0)

    def add_edge(self, edge):
        self.edges.append(edge)

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x_root, y_root = self.find(x), self.find(y)
        if x_root == y_root:
            return
        if self.rank[x_root] < self.rank[y_root]:
            self.parent[x_root] = y_root
        elif self.rank[x_root] > self.rank[y_root]:
            self.parent[y_root] = x_root
        else:
            self.parent[x_root] = y_root
            self.rank[y_root] += 1

    @staticmethod
    def compare(edge1, edge2):
        return edge1.weight - edge2.weight

    def kruskal(self):
        result: List[Edge] = []
        self.edges.sort(key=functools.cmp_to_key(self.compare))
        for edge in self.edges:
            if self.find(edge.a) != self.find(edge.b):
                result.append(edge)
                self.union(edge.a, edge.b)
        return result


graph = DisjointSet(4)
graph.add_edge(Edge(0, 1, 10))
graph.add_edge(Edge(0, 2, 6))
graph.add_edge(Edge(0, 3, 5))
graph.add_edge(Edge(1, 3, 15))
graph.add_edge(Edge(2, 3, 4))
print('MST:')
mst = graph.kruskal()
cost = 0
for edge in mst:
    print(f'{edge.a} -> {edge.b} = {edge.weight}')
    cost += edge.weight
print(cost)
