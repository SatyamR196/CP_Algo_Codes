#include<bits/stdc++.h> 
using namespace std;

#define int long long 
int mod = 1e9 + 7;

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

// nCr with modulo 
int single_ncr(int n, int r) {    // O(min(r,n-r))
    r = min(r,n-r) ;
    int num = 1, den = 1; 
    for(int i=1; i<=r; i++) {
        num = (num * (n-i+1)) % mod; 
        den = (den * i) % mod;
    }
    return (num * modInv(den)) % mod;
}
