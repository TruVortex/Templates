#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {

    int val;
    Node *l, *r;

    Node(int val) : val(val), l(nullptr), r(nullptr) {}
    Node(Node *l, Node *r) : val(0), l(l), r(r) {
        if (l) {
            val += l->val;
        }
        if (r) {
            val += r->val;
        }
    }
};

struct PersistentSegmentTree {

    int n, rootCnt;
    Node *roots[100001];

    SegmentTree(vector<int> &arr) : n(arr.size()), rootCnt(1) {
        roots[0] = build(arr, 0, n - 1);
    }

    Node *build(vector<int> &arr, int tl, int tr) {
        if (tl == tr) {
            return new Node(arr[tl]);
        }
        int tm = (tl + tr) / 2;
        return new Node(build(arr, tl, tm), build(arr, tm + 1, tr));
    }

    int sum(int prev, int l, int r) {
        return sum(roots[prev], 0, n - 1, l, r);
    }

    int sum(Node *node, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return node->val;
        }
        int tm = (tl + tr) / 2;
        return sum(node->l, tl, tm, l, min(r, tm)) + sum(node->r, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int prev, int pos, int val) {
        roots[rootCnt] = update(roots[prev], 0, n - 1, pos, val);
        rootCnt++;
    }

    Node *update(Node *node, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            return new Node(val);
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return new Node(update(node->l, tl, tm, pos, val), node->r);
        }
        return new Node(node->l, update(node->r, tm + 1, tr, pos, val));
    }
};

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5 };
    PersistentSegmentTree seg(arr);
    seg.update(0, 4, 6);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = j; k < 5; k++) {
                printf("%d %d %d\n", j, k, seg.sum(i, j, k));
            }
        }
        printf("\n");
    }
    return 0;
}
