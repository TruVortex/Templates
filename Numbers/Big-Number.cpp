#include <iostream>
#include <string>
//#include <math.h>

using namespace std;

struct BigNum {

    int arr[100];

    BigNum(string n = "") {
        for (int i = 0; i < 100; i++) {
            arr[i] = 0;
        }
        int i = 0;
        while (n.length() != 0) {
            arr[i] = n[n.length() - 1] - '0';
            n = n.substr(0, n.length() - 1);
            i++;
        }
    }

    void add(BigNum n) {
        for (int i = 0; i < 99; i++) {
            arr[i] += n.arr[i];
            if (arr[i] >= 10) {
                arr[i + 1]++;
                arr[i] -= 10;
            }
        }
    }

    string toString() {
        int i;
        for (i = 99; i >= 0; i--) {
            if (arr[i] != 0) {
                break;
            }
        }
        string ans = "";
        for (; i >= 0; i--) {
            ans += to_string(arr[i]);
        }
        return ans;
    }

    long long toLong() {
        return stoll(toString());
    }
};

int main() {
    BigNum a("23751862468957632907131205312375485123785621368947"), b("4765215596742196521562987089425106237623579236123");
    cout << a.toString() << " " << b.toString() << "\n";
    a.add(b);
    cout << a.toString() << " " << b.toString() << "\n";
    //b.multiply(a);
    //cout << a.toString() << " " << b.toString() << "\n";
    return 0;
}
