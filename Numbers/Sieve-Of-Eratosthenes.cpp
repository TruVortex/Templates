#include <stdio.h>
#include <vector>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    vector<int> primes = sieve(100);
    for (int primes : primes) {
        printf("%d\n", primes);
    }
    return 0;
}
