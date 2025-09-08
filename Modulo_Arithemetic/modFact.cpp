long long factorial(int k) {
    long long res = 1;
    for (int i = 2; i <= k; ++i) {
        res = (res * i) % mod;
    }
    return res;
}
