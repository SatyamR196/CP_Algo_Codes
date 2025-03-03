#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define INF 1e9
using state = pair<int,int>;

int n,m;
vector<vector<state>> graph;
vector<int>dist;

void bfs01(int st){
  deque<int>q;
  q.push_back(st) ;
  dist[st] = 0 ;
  
  while(!q.empty()){
    int cNode = q.front();
    q.pop_front();
    
    for(auto p : graph[cNode]){
      int neigh = p.F;
      int weight = p.S;
      if(dist[neigh] > dist[cNode]+ weight){
        
        dist[neigh] = dist[cNode] + weight ;
        if(weight==0) q.push_front(neigh);
        else q.push_back(neigh);
        
      }
    }
    
  }
}

int main() 
{
    cin>>n>>m;
    graph.resize(n+1);
    dist.assign(n+1,INF);
    
    for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      graph[a].push_back({b,c}) ;
      graph[b].push_back({a,c}) ;
    }
    
    for(int i=1;i<=n;i++){
      bfs01(i) ;
    }
    
    return 0;
}
