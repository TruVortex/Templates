#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct BloomFilter {

    int length, hashCount;
    vector<bool> bitarr;

    BloomFilter(int elements, double falsePositive) {
        length = -(elements * log(falsePositive)) / (log(2) * log(2));
        hashCount = log(2) * length / elements;
        bitarr.resize(length);
    }

    void add(string element) {
        size_t h1 = hash<string>{}(element);
        for (int i = 0; i < hashCount; i++) {
            size_t h2 = hash<string>{}(to_string(i));
            size_t digest = h1 ^ (h2 << 1);
            int idx = ((digest % length) + length) % length;
            bitarr[idx] = true;
        }
    }

    bool check(string element) {
        size_t h1 = hash<string>{}(element);
        for (int i = 0; i < hashCount; i++) {
            size_t h2 = hash<string>{}(to_string(i));
            size_t digest = h1 ^ (h2 << 1);
            int idx = ((digest % length) + length) % length;
            if (!bitarr[idx]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    BloomFilter bf(2, 0.01);
    bf.add("asd");
    cout << "NY"[bf.check("asd")] << "\n";
    cout << "NY"[bf.check("sad")] << "\n";
    bf.add("sad");
    cout << "NY"[bf.check("sad")] << "\n";
    cout << "NY"[bf.check("sa")] << "\n";
    cout << "NY"[bf.check("fadhofisho")] << "\n";
    return 0;
}
