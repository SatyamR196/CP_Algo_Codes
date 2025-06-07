//! Find the PF of given number x, answer each query in O(log(x)) ;
//~ Link : https://onecompiler.com/cpp/43m356hn4
//? Algo :
//~ Create a smallest prime array, sp[i] : smallest primeFactor of i ;
//~ Using similar techinque as seive of eratosthenes, loop from 2 to n,
//~ set for all multiples of prime 2, sp[] = 2, repeat this for 3,4...n
//~ Once this sp array is ready, Make primeFactor() fxn using PF(x) = sp[x] * PF(x/sp[x]) ;
//~ Either recusively or in loop, and we will get all PFs in TC=O{log(x)} 
#include <bits/stdc++.h>
using namespace std ;

vector<int> get_sp_arr(int n){
  
  vector<int>sp(n+1) ;
  for (int i = 2; i <= n; i++) {
    sp[i] = i; // Initially assume each number is prime
  }

  for (int i = 2; i <= n; i++) {
    if (sp[i] == i) { // if i is prime then for all it's multiple sp[j]=i
      for (int j = 2 * i; j <= n; j += i) {
        //? set the smallest prime factor of j = i if it's not changed earlier
        if (sp[j] == j) sp[j] = i; 
      }
    }
  }
  
  return sp ;
}

vector<int>sp ; // make a global smallest prime array;
//~ sp[i] : smallest primeFactor of i ;

vector<int> primeFactors(int x){
  vector<int>factors;
  while(x>1){
    factors.push_back(sp[x]) ;
    x/=sp[x] ;
    //! for any number x , PF(x) = sp[x] * PF of (x/sp[x]), [recursive relation]
  }
  return factors;
}

int main() 
{ 
  int n ;// max num for which PF can be asked
  cin>>n;
  sp = get_sp_arr(n) ;
  for(auto ele : sp){
    cout<<ele<<" ";
  }
  cout<<endl;
  for(auto ele : primeFactors(31) ){
    cout<<ele<<" ";
  }
  // cout<<primeFactors(34,100) ;
  return 0;
}
