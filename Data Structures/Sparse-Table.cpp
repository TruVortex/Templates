#include <stdio.h>
#include <vector>
#define minn(a, b) ((a) < (b) ? (a) : (b))
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct SparseTable {

    int N, K = 25;
    vector<int> log;
    vector<vector<int>> st;

    SparseTable(vector<int> &arr) : N(arr.size()), log(N + 1), st(N + 1, vector<int>(K + 1)) {
        log[1] = 0;
        for (int i = 2; i <= N; i++) {
            log[i] = log[i / 2] + 1;
        }
        for (int i = 0; i < N; i++) {
            st[i][0] = arr[i];
        }
        for (int j = 1; j <= K; j++) {
            for (int i = 0; i + (1 << j) <= N; i++) {
                st[i][j] = minn(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int min(int l, int r) {
        int j = log[r - l + 1];
        return minn(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main() {
    SparseTable st({ 2, 1, 5, 4, 3 });
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            printf("%d %d %d\n", i, j, st.min(i, j));
        }
    }
}
