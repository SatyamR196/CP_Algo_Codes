#include <bits/stdc++.h>
using namespace std;
// TC = O(n*log(log(n)) ;
vector<int>seive(int n){
  vector<int>num(n+1,1) ;
  num[0] = 0 ;
  num[1] = 0 ;
  for(int i=2 ;i<=n ;i++){
    if(num[i]){
      for(int j = 2*i ; j<=n ; j+=i) num[j] = 0 ;
    }
  }
  
  return num ;
}

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
  auto v = seive_opt(50) ;
  for(auto ele : v){
    cout<<ele<<" ";
  }
  return 0;
}
