//_ DP Form 1 : Knapsack : Choose a subset which satisfies the given conditions
//! Key Idea : Iterate over list of items, then either Choose to pick or reject for each items
// Link : https://onecompiler.com/cpp/43mhshc8e
//? Knapsack with restriction that sum_of_weight divisible by M . 
//! Idea : when you complete your pick and reach the base case, check if sum is divisible
//! by M, if yes then return 0(valid ✔️) else return -INF(invalid) because this is a 
//! maximization problem then if some path has too much -ve val it will be ignored in transiton

#include<bits/stdc++.h> 
using namespace std;

int INF = 1e9 ;
int wi[21] ;
int vi[21] ;
int N,W ;
int cache[21][101] ; //~ <level,weight>
int M = 10 ;
int dp(int level,int w_left){
    //base case
    if(level == N+1){
      int sum_of_weight = (W - w_left) ; 
      // cout<<"Weight Sum : "<<sum_of_weight<<endl;
      if(sum_of_weight % M ==0) return 0 ; // valid case
      else return -INF ; // invalid case 
    } 
  
    // cache check
    if(cache[level][w_left] != -1) return cache[level][w_left] ;

    //transiton :
    int ans = -INF ;
    //choice 1 : don't take
    ans = max(ans,dp(level+1,w_left)) ;
    //choice 2 : take it in
    if(wi[level] <= w_left){
        ans = max(ans, vi[level] + dp(level+1, w_left - wi[level])) ;
    }

    
    //save and return ans ;
    return cache[level][w_left] = ans ;
}

//! This fxn return the item we need to pick for max Value within weight limits.
vector<int> print_items(){
  cout<<"item_no : ";
  int w_left = W ;
  vector<int>itemTaken ;
  
  for(int i=1 ; i<=N ; i++){
    int dontakeVal = dp(i+1,w_left) ;
    int takeVal = (w_left>=wi[i]) ? vi[i]+dp(i+1,w_left-wi[i]) : 0 ;
    
    if(takeVal >= dontakeVal){
      itemTaken.push_back(i) ;
      w_left -= wi[i] ;
      cout<<i<<", "; 
    }
    
  }
  cout<<endl;
  return itemTaken ;
}

void solve(){    
    cin>>N>>W ;
    for(int i=1;i<=N;i++){
        cin>>wi[i]>>vi[i] ;
    }
    memset(cache,-1,sizeof(cache)) ;
    // debug(cache) ;
    cout<<dp(1,W)<<endl ;
    // print_items() ;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
