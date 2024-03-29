#include <stdio.h>
#include <vector>
#include <algorithm>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct SegmentTree {

    int n;
    vector<int> t;

    SegmentTree(vector<int> &arr) : n(arr.size()), t(2 * n) {
        construct(arr, 1, 0, n - 1);
    }

    void construct(vector<int> &arr) {
        construct(arr, 1, 0, n - 1);
    }

    void construct(vector<int> &arr, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            construct(arr, v + 1, tl, tm);
            construct(arr, v + 2 * (m - tl + 1), tm + 1, tr);
            t[v] = t[v + 1] + t[v + 2 * (m - tl + 1)];
        }
    }

    int sum(int l, int r) {
        return sum(1, 0, n - 1, l, r);
    }

    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v + 1, tl, tm, l, min(r, tm)) + sum(v + 2 * (tm - tl + 1), tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v + 1, tl, tm, pos, val);
            } else {
                update(v + 2 * (tm - tl + 1), tm + 1, tr, pos, val);
            }
            t[v] = t[v + 1] + t[v + 2 * (tm - tl + 1)];
        }
    }
};

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5 };
    SegmentTree seg(arr);
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            printf("%d %d %d\n", i, j, seg.sum(i, j));
        }
    }
}
