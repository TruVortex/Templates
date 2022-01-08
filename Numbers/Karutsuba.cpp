#include <stdio.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

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

int karutsuba(int a, int b) {
    if (a < 10 || b < 10) {
        return a * b;
    }
    int minn = min(log10(a) + 1, log10(b) + 1) / 2;

    int hi1 = a / fastPow(10, minn), lo1 = a % (int) fastPow(10, minn), hi2 = b / fastPow(10, minn), lo2 = b % (int) fastPow(10, minn);
    
    int z0 = karutsuba(lo1, lo2), z1 = karutsuba(lo1 + hi1, lo2 + hi2), z2 = karutsuba(hi1, hi2);

    return (z2 * fastPow(10, minn + minn)) + ((z1 - z2 - z0) * fastPow(10, minn)) + z0;
}

int main() {
    for (int i = 11; i <= 20; i++) {
        printf("%d\n", karutsuba(i, i + i - 1));
    }
}
