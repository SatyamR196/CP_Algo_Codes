// If this shortest cycle is -ve that means -ve cycle is present.
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


void solve(){
    cin>>n>>m;
    graph.resize(n+1,vector<int>(n+1,INF)) ;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = min(w,graph[u][v]) ;
        graph[v][u] = min(w,graph[v][u]) ;
    }
    
    // Assigning diagonal to zero, if that is not set to 0 then 
    //graph[i][i] will contain the shortest cycle from node i to node i;
    // So here we will skip this part
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(i==j) graph[i][j]=0 ;
    //     }
    // }

    //Floyed-Warshall 
    for(int k=1;k<=n;k++){
       for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
              if(graph[i][k]== INF || graph[k][j]== INF) continue;
              if(graph[i][k]+graph[k][j] < graph[i][j] ){
                graph[i][j] = graph[i][k]+graph[k][j];
              }
        } 
      }
    }
    
    int shortest_cycle=INF;
    for(int i=1;i<=n;i++){
      shortest_cycle = min(shortest_cycle,graph[i][i]);
    }
    cout<<shortest_cycle<<endl;
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
