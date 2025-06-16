// Segmented sieve is used to generate primes from L to R where L,R <= 1e12.
#define ll long long

// Simple Sieve of Eratosthenes: Generates all prime numbers up to n
vector<int> sieve(ll n) {
    // Boolean array to mark whether a number is prime.
    vector<bool> isPrime(n+1, true); //initially mark all nums as primes.
    vector<int> primes; // This vector will store the the primes upto n .

    // 0 and 1 are not primes, so mark them false.
    isPrime[0] = isPrime[1] = false;
    
    // Iterate through all numbers from 2 to n
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            // If i is prime, add to the list
            primes.push_back(i);
            // Mark all multiples of i as non-prime
            for(ll j = (ll)i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return primes;
}

// Segmented sieve to find primes in range [L, R]
vector<int> segmented_sieve(int L, int R) {
    // Phase 1: Generate all base primes up to sqrt(R)
    // These primes will be used to mark non-primes in [L, R]
    vector<int> base_primes = sieve(ceil(sqrt(R)));

    // Phase 2: Mark non-primes in range [L, R] using the base primes
    vector<bool> is_prime(R-L+1, true); // Initially assume all numbers in [L, R] are prime

    // Handle the case when L = 1 separately since 1 is not a prime
    if(L == 1) is_prime[0] = false;

    // For each base prime, mark its multiples in [L, R] as non-prime
    for(auto prime : base_primes) {
        // Find the smallest multiple of `prime` >= L = ceil(L/prime) * prime
        int ceil_l_by_p = (L + prime - 1) / prime;
        int cur_mul = prime * ceil_l_by_p;

        // Ensure we start from prime^2 or above to avoid marking the prime itself
        cur_mul = max(prime * prime, cur_mul);

        // Mark all multiples of `prime` in the range [L, R]
        while(cur_mul <= R) {
            is_prime[cur_mul - L] = false;
            cur_mul += prime;
        }
    }

    // Collect all numbers that remained marked as prime
    vector<int> primes_l_to_r;
    for(int i = 0; i < R - L + 1; i++) {
        if(is_prime[i]) {
            primes_l_to_r.push_back(i + L);
        }
    }

    return primes_l_to_r;
}
