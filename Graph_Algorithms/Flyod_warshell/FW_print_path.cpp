#include<bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using ll = long long ;
#define endl "\n"
#define int long long
int mod = 1e9+7 ;

int n,m,q;
ll INF=1e18 ;

vector<vector<int>>graph;// in matrix form
vector<vector<int>>parent;
// What this parent will store
// parent[i][j] represents, i --> a --> b --> ... --> c --> parent[i][j] or k --> j

void printPath(int i,int j){
  if(i!=j) printPath(i,parent[i][j]) ;
  cout<<j<<" ";
}

void solve(){
    cin>>n>>m;
    graph.resize(n+1,vector<int>(n+1,INF)) ;
    parent.resize(n+1,vector<int>(n+1)) ;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = min(w,graph[u][v]) ;
        graph[v][u] = min(w,graph[v][u]) ;
    }
    
    // Assigning diagonal to zero, if that is not set to 0 then graph[i][i] will contain the shortest cycle containg node i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) graph[i][j]=0 ;
        }
    }
    // Initializing parent:
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
        parent[i][j] = i ;
      }
    }
    debug(parent) ;
    //Floyed-Warshall 
    for(int k=1;k<=n;k++){
       for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][k]== INF || graph[k][j]== INF) continue;
                if(graph[i][k]+graph[k][j] < graph[i][j] ){
                  graph[i][j] = graph[i][k]+graph[k][j];
                  // parent[i][j] = parent[k][j] ; // original one below is my modification
                  parent[i][j] = k ;  
                  // since we came to j via node k, hence parent of j is node k. 
                }
            }
        } 
    }
    
    printPath(1,3);
    cout<<endl;
    debug(graph,parent) ;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
