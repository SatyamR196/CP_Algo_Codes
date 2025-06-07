vector<long long> prime_factors(long long x) {
    vector<long long> factors;

    // Step 1: Factor out 2
    while (x % 2 == 0) {
        factors.push_back(2);
        x /= 2;
    }

    // Step 2: Factor out odd numbers from 3 to sqrt(x)
    for (long long i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }

    // Step 3: If x is still > 1, it must be a prime
    if (x > 1) {
        factors.push_back(x);
    }

    return factors;
}
