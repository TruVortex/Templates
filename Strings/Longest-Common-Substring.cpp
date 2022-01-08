#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonSubstring(string a, string b) {
    vector<vector<int>> vect(a.length(), vector<int>(b.length()));
    int len = 0;
    string ans = "";
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (a[i] == b[j]) {
                if (i == 0 || j == 0) {
                    vect[i][j] = 1;
                } else {
                    vect[i][j] = vect[i - 1][j - 1] + 1;
                }
                if (vect[i][j] > len) {
                    len = vect[i][j];
                    ans = a.substr(i - len + 1, len);
                }
            } else {
                vect[i][j] = 0;
            }
        }
    }
    return ans;
}

int main() {
    cout << longestCommonSubstring("helloWorldasdjioajfad", "dasjHelloWorlddasdji") << "\n";
    cout << longestCommonSubstring("ahelloWorldasdjioajfad", "dasjHelloWorlddasdji") << "\n";
    cout << longestCommonSubstring("ahelloWorldasdjioajfad", "dasjHelloWorld") << "\n";
    cout << longestCommonSubstring("helloWorld", "helloWorld") << "\n";
}
