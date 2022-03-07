#include <iostream>
#include <string>
#include <vector>
#define max(a, b) ((a) < (b) ? (b) : (a))

using namespace std;

string read(vector<vector<int>>& dp, string a, string b, int x, int y) {
    if (x == 0 || y == 0) {
        return "";
    } else if (a[x - 1] == b[y - 1]) {
        return read(dp, a, b, x - 1, y - 1) + a[x - 1];
    } else if (dp[x - 1][y] > dp[x][y - 1]) {
        return read(dp, a, b, x - 1, y);
    }
    return read(dp, a, b, x, y - 1);
}

string lcs(string a, string b) {
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1));
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return read(dp, a, b, a.length(), b.length());
}

int main() {
    cout << lcs("XMJYAUZ", "MZJAWXU");
    return 0;
}
