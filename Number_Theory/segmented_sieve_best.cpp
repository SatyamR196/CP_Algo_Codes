#define ll long long
vector<int> sieve(ll n) {
    // Return a vector of prime numbers up to n, not a boolean array
    vector<bool> isPrime(n+1, true);
    vector<int> primes;
    
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            // Mark multiples as non-prime
            for(ll j = (ll)i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return primes;
}

vector<int> segmented_sieve(int L, int R) {
    // Phase 1 : use sieve to precompute primes in range [1...sqrt(R)] as base primes
    vector<int> base_primes = sieve(ceil(sqrt(R)));

    // Phase 2 : sieve the range [L...R] using the primes found in range [1...sqrt(R)]
    vector<bool> is_prime(R-L+1, true);
    if(L == 1) is_prime[0] = false;

    for(auto prime:base_primes) {
        int ceil_l_by_p = (L + prime - 1) / prime;
        int cur_mul = prime * ceil_l_by_p;
        cur_mul = max(prime * prime, cur_mul);

        while(cur_mul <= R) {
            is_prime[cur_mul-L] = false;
            cur_mul += prime;
        }
    }

    vector<int> primes_l_to_r;
    for(int i=0; i<R-L+1; i++) {
        if(is_prime[i]) {
            primes_l_to_r.push_back(i+L);
        }
    }

    return primes_l_to_r;
}
