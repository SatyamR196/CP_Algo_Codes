// Problem Link : https://leetcode.com/problems/count-number-of-trapezoids-i

class Solution {
public:
    const int mod = 1e9+7 ;

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

    long long factorial(int k) {
        long long res = 1;
        for (int i = 2; i <= k; ++i) {
            res = (res * i) % mod;
        }
        return res;
    }

    // without mod optimizatin won't work.
    // long long nCr(int n, int r) {
    //     if (r < 0 || r > n) {
    //         return 0; // Invalid combination
    //     }
    //     if (r == 0 || r == n) {
    //         return 1;
    //     }
    //     if (r > n / 2) { // Optimization: C(n,r) = C(n, n-r)
    //         r = n - r;
    //     }
    //     return factorial(n) / (factorial(r) * factorial(n - r));
    // }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;

        long long num = factorial(n);
        long long denom = (factorial(r) * factorial(n - r)) % mod;

        return (num * modInv(denom)) % mod;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long,long>freq ; 
        // grouping point on basis of y-coordinate, <y-coordinate, no. of pts>
        for(auto v : points){
            freq[v[1]]++ ;
        }

        long long choiceSum = 0 ; // sum(all co-linear pts)i
        long long choiceSqrSum = 0 ; // sum(sqr(all co-linear pts))i

        for(auto p : freq){
            long long cnt = p.second ;
            long long choose2 = nCr(cnt,2) ;
            choiceSum = (choiceSum+choose2)%mod ;
            choiceSqrSum = (choiceSqrSum+(choose2*choose2)%mod)%mod ;
        }

        // cout<<choiceSum<<" "<<choiceSqrSum<<endl;
        long long total = (choiceSum*choiceSum)%mod ;
        long long ans = (total - choiceSqrSum + mod) %mod ; // safe subtraction
        ans = (ans * modInv(2))%mod ;

        return ans%mod ;
    }
};
