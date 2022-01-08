#include <stdio.h>

using namespace std;

int fastPow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int temp = fastPow(a, b / 2);
    if (b % 2 == 1) {
        return temp * temp * a;
    } else {
        return temp * temp;
    }
}

int main() {
    for (int i = 1; i <= 100; i++) {
        printf("%d\n", fastPow(i, 4));
    }
}
