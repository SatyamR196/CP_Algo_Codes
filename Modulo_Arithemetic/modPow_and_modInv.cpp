// Modular exponentiation to compute (base^exp) % mod
long long modPow(long long base, long long exp){
    if(exp==0) return 1 ;
    
    if(exp%2==1){
        return (base*modPow(base,exp-1))%mod ;
    }else{
        long long half = modPow(base,exp/2) ;
        return (half*half)%mod ;
    }
}

// Modular inverse using Fermat's little theorem (only if mod is prime)
long long modInv(long long a) {
    return modPow(a, mod - 2);
}
