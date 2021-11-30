#include <stdio.h>
#include <unordered_map>

using namespace std;

struct DisjointSet {

    unordered_map<int, int> parent, rank;

    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            makeSet(i);
        }
    }

    void makeSet(int x) {
        parent[x] = x;
        rank[x] = 0;
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
            rank[yRt] = rank[xRt] + 1;
        }
    }
};

int main() {
    DisjointSet djs(5);
    djs.unionn(0, 2);
    djs.unionn(2, 4);
    djs.unionn(1, 3);
    if (djs.find(0) == djs.find(4)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    if (djs.find(0) == djs.find(1)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
