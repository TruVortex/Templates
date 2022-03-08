#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int leveshteinDistance(string a, string b, int costDel, int costInsert, int costReplace) {
    int n = b.length();
    vector<int> vect1(n + 1), vect2(n + 1);
    for (int i = 0; i <= n; i++) {
        vect1[i] = i * costInsert;
    }
    for (int i = 0; i < a.length(); i++) {
        vect2[0] = (i + 1) * costDel;
        for (int j = 0; j < n; j++) {
            int delCost = vect1[j + 1] + costDel, inCost = vect2[j] + costInsert, subCost;
            if (a[i] == b[j]) {
                subCost = vect1[j];
            } else {
                subCost = vect1[j] + costReplace;
            }
            vect2[j + 1] = min(delCost, min(inCost, subCost));
        }
        vect1 = vect2;
    }
    return vect1[n];
}

int main() {
    cout << leveshteinDistance("intention", "execution", 1, 2, 4);
    return 0;
}
