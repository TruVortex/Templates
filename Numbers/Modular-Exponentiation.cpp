int modPow(int a, int b, int m) {
    if (b == 0) {
        return 1;
    }
    long long temp = modPow(a, b / 2, m) % m;
    if (b % 2 == 1) {
        return ((temp * temp) % m) * a % m;
    } else {
        return ((temp * temp) % m);
    }
}
