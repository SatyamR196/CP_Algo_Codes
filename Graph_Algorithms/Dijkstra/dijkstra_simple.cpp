// dijkstra Algo Code
/* Sample test case:
7 8
1 2 1
1 4 0
1 6 2
6 7 10
6 2 4
4 5 4
5 3 6
2 3 2
*/
/* Sample test case:
3 3
0 1 2
1 2 -7
2 0 3
if visited check is not there in some cases it may give TLE, and in case of -ve cycle it will give TLE for sure in absence of this.
*/
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
lli INF = 1e18;
int n,m;
using state = pair<int,int>;

#define F first
#define S second

vector<vector<state>>graph;
vector<lli>dist;
vector<int>visited;

void dijkstra(int st){
  dist[st] = 0 ;
  priority_queue<state,vector<state>,greater<state>>pq; // creation of min heap
  pq.push({0,st});
  
  while(!pq.empty()){
    state cNode = pq.top();
    pq.pop() ;
    
    if(visited[cNode.S]) continue;
    visited[cNode.S] = 1;
    
    for(auto ele : graph[cNode.S]){  // graph {node,weight}
      int neigh = ele.F;
      int w = ele.S ;
      if(dist[neigh] > dist[cNode.S] + w ){
        dist[neigh] = dist[cNode.S] + w ;
        pq.push({dist[neigh],neigh});
      }
    }
    
  }
}

int main() 
{ 
  cin>>n>>m;
  graph.clear();
  dist.clear();
  visited.clear();
  graph.resize(n+1);
  dist.assign(n+1,INF) ;
  visited.assign(n+1,0) ;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    graph[a].push_back({b,c});
    // graph[b].push_back({a,c});
  }
  
  dijkstra(1);
  for(auto ele : dist){
    cout<<ele<<" ";
  }
  cout<<endl;
  for(auto ele : visited){
    cout<<ele<<" ";
  }
}
