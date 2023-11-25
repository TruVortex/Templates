#include <stdio.h>
#include <vector>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct FenwickTree {
    
    vector<int> bit;

    FenwickTree(int n) : bit(n + 1) {}

    FenwickTree(vector<int> vect) : bit(vect.size() + 1) {
        for (int i = 1; i <= vect.size(); i++) {
            bit[i] += vect[i - 1];
            int r = (i | (i - 1)) + 1;
            if (r <= vect.size()) {
                bit[r] += bit[i];
            }
        }
    }

    int parent(int n) {
        return n - (n & (-n));
    }

    int next(int n) {
        return n + (n & (-n));
    }

    int getNum(int n) {
        return getSum(n) - getSum(n - 1);
    }

    int getSum(int n) {
        int sum = 0;
        n++;
        while (n > 0) {
            sum += bit[n];
            n = parent(n);
        }
        return sum;
    }

    int getSum(int l, int r) {
        return getSum(r) - getSum(l - 1);
    }

    void update(int n, int x) {
        n++;
        while (n < bit.size()) {
            bit[n] += x;
            n = next(n);
        }
    }

    void set(int n, int x) {
        update(n, x - getNum(n));
    }
};

int main() {
    FenwickTree ft(5);
    ft.update(0, 1);
    ft.update(1, 5);
    ft.update(2, 3);
    ft.update(3, 4);
    ft.update(4, 5);
    printf("%d\n", ft.getNum(2));
    ft.set(2, 4);
    printf("%d\n", ft.getNum(2));
    printf("%d\n", ft.getSum(3));
    printf("%d\n", ft.getSum(1, 3));
}
