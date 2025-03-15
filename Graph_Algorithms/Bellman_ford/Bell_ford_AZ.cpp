#include<bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using ll = long long ;
#define endl "\n"
#define int long long
int mod = 1e9+7 ;

vector<vector<int>>graph;// graph in form edge list not node list
vector<int>dist;
int n,m;
ll INF = 1e18;

bool bell_ford(int st){
    dist[st] = 0 ;
    
    // Relaxing n-1 times
    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(int j=0; j<m; j++){
            int u = graph[j][0];            
            int v = graph[j][1];            
            int w = graph[j][2];            

            if(dist[u]==INF) continue;

            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w ;
                flag = true;
            }
        }
        if(!flag) break;
    }
    // Relaxing nth(last) time
    for(int j=0; j<m; j++){
        int u = graph[j][0];            
        int v = graph[j][1];            
        int w = graph[j][2]; 

        if(dist[u]==INF) continue;
        
        if(dist[u]+w < dist[v]){
            return 1 ; // return true if +ve cycle exists
        } 
    }

    return 0;
}

void solve(){
    cin>>n>>m;
    graph.resize(m);
    dist.assign(n+1,INF);
    dist[0] = 0 ;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[i].push_back(u) ;
        graph[i].push_back(v) ;
        graph[i].push_back(w) ;
        //To detect +ve cycle we just put -w in place of w.
    }

    bool isPosCycle = bell_ford(1);
    isPosCycle == 1 ? cout<<-1<<endl : cout<<-dist[n]<<endl ;
  // If -ve cycle exists then print -1 else print highest weighted path
  // For detection and dealing with +ve cycles, just replace w --> (-w)
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
