#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<int> kmp(string str, string pattern) {
    int i = 0, j = -1, n = str.length(), m = pattern.length();
    vector<int> t(m + 1);
    t[0] = -1;
    while (i < m) {
        while (j >= 0 && pattern[i] != pattern[j]) {
            j = t[j];
        }
        i++;
        j++;
        t[i] = j;
    }
    i = 0;
    j = 0;
    vector<int> indices;
    while (i < n) {
        while (j >= 0 && str[i] != pattern[j]) {
            j = t[j];
        }
        i++;
        j++;
        if (j == m) {
            indices.push_back(i - j);
            j = t[j];
        }
    }
    return indices;
}

int main() {
    vector<int> indices = kmp("SEVENSEVNSEVENSEVENadASFDAIGDOHO", "SEVEN");
    for (int index : indices) {
        printf("%d\n", index);
    }
    return 0;
}
