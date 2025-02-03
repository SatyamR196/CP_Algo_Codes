#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using ll = long long ;

vector<vector<int>> graph ;
vector<int>visited;
vector<int>dist;
int n,m;

void bfs(int sNode){
  queue<int>q;
  q.push(sNode) ;
  visited[sNode] = 1 ;
  dist[sNode] = 0 ;
  
  while(!q.empty()){
    int node = q.front();
    q.pop();
    // cout<<node<<" ";
    for(auto ele : graph[node]){
      if(!visited[ele]){//If it is not already pushed into queue
        q.push(ele) ;
        visited[ele] = 1 ;
        dist[ele] = dist[node]+1 ;
        cout<<ele<<" ";
      }
    }
    cout<<endl;
  }
}

int main() 
{ 
  // Taking Input :
  cin>>n>>m ;
  graph.resize(n+1);
  visited.assign(n+1,0);
  dist.assign(n+1,-1);
  
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  cout<<1<<endl;
  bfs(1);
}
