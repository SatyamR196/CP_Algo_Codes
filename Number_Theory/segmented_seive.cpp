//! Count the number of primes from [a,b] where a,b <=1e12 but b-a <=1e6
// Link : https://onecompiler.com/cpp/43m2625q7
// AZ lecture : https://maang.in/playlists/Day-23-Number-Theory-Ideas-to-know-3605?resourceUrl=pl3605-rs8468&returnUrl=%5B%22%2Fcohorts%2FAZ-Premium-Cohort-8-24%3Ftab%3Dassignments%22%5D
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long

// Using seive of eratosthenes to check primes till Sqrt(b) ;
vector<int>seive_opt(int n){
  vector<int>num(n+1,1) ;
  num[0] = 0 ;
  num[1] = 0 ;
  for(int i=2 ;i<=n ;i++){
    if(num[i]){
      for(long long j = 1LL*i*i ; j<=n ; j+=i) num[j] = 0 ;
    }
  }
  
  return num ;
}

int main() 
{ 
  int a,b ;
  cin>>a>>b ;
  //? All primes in range till sqrt(b) ;
  vector<int> small_primes = seive_opt(sqrt(b)) ;
  
  //? All primes in range a to b ;
  vector<int> large_primes(b-a+1,1) ;
  //~ large_primes[a] <--> large_primes[0] ;
  //-                                                                      
  for(int i=2 ; i<=sqrt(b); i++){
    //* Skip nums that are not prime
    if(small_primes[i] == 0) continue ;
    
    //? mark all it's multiples as zero in [a,b] ;
    //~ find first_multiple = (a/curr_prime)ceil * curr_prime ;
    int curr_multiple = ((a+i-1)/i) * i ;
    
    while(curr_multiple<=b){
      //! if [0,sqrt(b)] lies in range[a,b] then be careful,
      //! a = 2, b = 36 then [0,6] lies in [2,36] so 
      //! don't set large_primes[2-2]= 0;
      if(curr_multiple!=i){
        //? large_primes[a] <--> large_primes[0], hence subract index ;
        large_primes[curr_multiple-a] = 0 ;
      }
      curr_multiple += i ;
    }
  }
  //-
  cout<<"small_primes : ";
  for(auto ele : small_primes){
    cout<<ele<<" ";
  }
  cout<<endl;
  int cnt = 0 ;
  cout<<"large_primes : ";
  for(auto ele : large_primes){
    if(ele==1) cnt++ ;
    cout<<ele<<" ";
  }
  cout<<endl;
  cout<<"primes in [a,b] : ";
  for(int i=0 ; i<large_primes.size() ; i++){
    if(large_primes[i])cout<<i+a<<" ";
  }
  cout<<endl;
  cout<<"Number of Primes in [a,b] : "<<cnt<<endl;
  return 0;
}
