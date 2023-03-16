#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSet {

    struct Edge {

        int a, b, weight;

        Edge() {
            a = -1;
            b = -1;
            weight = -1;
        }

        Edge(int a, int b, int weight) {
            this->a = a;
            this->b = b;
            this->weight = weight;
        }
    };

    vector<Edge> edges;
    vector<int> parent, rank;

    DisjointSet(int v) : rank(v) {
        for (int i = 0; i < v; i++) {
            parent.push_back(i);
        }
    }

    void addEdge(Edge edge) {
        edges.push_back(edge);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionn(int x, int y) {
        int xRt = find(x), yRt = find(y);
        if (xRt == yRt) {
            return;
        }
        if (rank[xRt] < rank[yRt]) {
            parent[xRt] = yRt;
        } else if (rank[xRt] > rank[yRt]) {
            parent[yRt] = xRt;
        } else {
            parent[xRt] = yRt;
            rank[yRt]++;
        }
    }

    static int kruskalCmp(Edge a, Edge b) {
        return a.weight < b.weight;
    }

    vector<Edge> kruskal() {
        vector<Edge> result;
        sort(edges.begin(), edges.end(), kruskalCmp);
        for (const Edge &edge : edges) {
            if (find(edge.a) != find(edge.b)) {
                result.push_back(edge);
                unionn(edge.a, edge.b);
            }
        }
        return result;
    }
};

int main() {
    DisjointSet graph(4);
    graph.addEdge(Edge(0, 1, 10));
    graph.addEdge(Edge(0, 2, 6));
    graph.addEdge(Edge(0, 3, 5));
    graph.addEdge(Edge(1, 3, 15));
    graph.addEdge(Edge(2, 3, 4));
    printf("MST:\n");
    int cost = 0;
    vector<Edge> mst = graph.kruskal();
    for (const Edge &edge : mst) {
        printf("%d -> %d = %d\n", edge.a, edge.b, edge.weight);
        cost += edge.weight;
    }
    printf("Cost: %d\n", cost);
    return 0;
}
