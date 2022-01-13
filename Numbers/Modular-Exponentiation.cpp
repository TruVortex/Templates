int modPow(int n, int exp, int m) {
    if (exp == 1) {
        return n;
    }
    return n * modPow(n, exp - 1, m) % m;
}
