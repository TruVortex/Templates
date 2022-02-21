#include <iostream>
#include <string>

using namespace std;

struct BigNum {

    int arr[100];

    BigNum(string n = "") {
        for (int i = 0; i < 100; i++) {
            arr[i] = 0;
        }
        for (int i = 0; i < n.length(); i++) {
            arr[i] = n[n.length() - i - 1] - '0';
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

    void subtract(BigNum n) {
        for (int i = 0; i < MAXN; i++) {
            arr[i] -= n.arr[i];
            if (arr[i] < 0) {
                arr[i + 1]--;
                arr[i] += 10;
            }
        }
    }

    void multiply(BigNum n) {
        BigNum temp;
        for (int i = 0; i < 49; i++) {
            for (int j = 0; j < 49; j++) {
                temp.arr[i + j] += arr[i] * n.arr[j];
            }
        }
        for (int i = 0; i < 99; i++) {
            if (temp.arr[i] >= 10) {
                temp.arr[i + 1] += temp.arr[i] / 10;
                temp.arr[i] %= 10;
            }
            arr[i] = temp.arr[i];
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
    BigNum a("237518624689576329071312053123754851237856213947"), b("47652155967421965215629870894251062376239236123");
    cout << a.toString() << " " << b.toString() << "\n";
    a.add(b);
    cout << a.toString() << " " << b.toString() << "\n";
    b.multiply(a);
    cout << a.toString() << " " << b.toString() << "\n";
    return 0;
}
