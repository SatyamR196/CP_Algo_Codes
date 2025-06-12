//_ DP Form 1 : Knapsack : Choose a subset which satisfies the given conditions
//! Key Idea : Iterate over list of items, then either Choose to pick or reject for each items
//? 0-INF Knapsack with solution print :
#include<bits/stdc++.h> 
using namespace std;

int wi[21] ;
int vi[21] ;
int N,W ;
int cache[21][101] ; //~ <level,weight>

int dp(int level,int w_left){
    //base case
    if(level == N+1) return 0 ;
  
    // cache check
    if(cache[level][w_left] != -1) return cache[level][w_left] ;

    //transiton :
    int ans = 0 ;
    //choice 1 : don't take and move 
    ans = max(ans,dp(level+1,w_left)) ;
    //choice 2 : Take a same item again( 0-INF Knapsack) and remain on same level
    if(wi[level] <= w_left){
        ans = max(ans, vi[level] + dp(level, w_left - wi[level])) ;
    }
    //? Note that these 2 transitions are sufficient no need for choice: take and move to next level
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
    int takeVal = (w_left>=wi[i]) ? vi[i]+dp(i,w_left-wi[i]) : 0 ;
    
    if(takeVal >= dontakeVal && w_left>=wi[i]){
      itemTaken.push_back(i) ;
      w_left -= wi[i] ;
      cout<<i<<", "; 
      i--;
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
    print_items() ;
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
