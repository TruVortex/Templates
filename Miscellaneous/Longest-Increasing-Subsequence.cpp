#include <stdio.h>
#include <vector>
#include <algorithm>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int lis(vector<int> vect) {
    vector<int> dp;
    for (int x : vect) {
        int idx = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        if (idx == dp.size()) {
            dp.push_back(x);
        } else {
            dp[idx] = x;
        }
    }
    return dp.size();
}

int main() {
    vector<int> vect;
    int n;
    scan(n);
    for (int i = 0, x; i < n; i++) {
        scan(x);
        vect.push_back(x);
    }
    printf("%d", lis(vect));
    return 0;
}
