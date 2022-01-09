#include <stdio.h>
#include <math.h>

using namespace std;

int numLength(int n) {
    return log10(n) + 1;
}

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", numLength(i * 149));
    }
}
