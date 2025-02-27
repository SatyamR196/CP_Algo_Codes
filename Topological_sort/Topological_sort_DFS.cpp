#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>graph;
vector<int>topo;
vector<int>visited;

void dfs(int node){
  visited[node]=1;
  for(auto ele: graph[node]){
    if(!visited[ele]){
      dfs(ele);
    }
  }
  topo.push_back(node);
}

int main() 
{
  cin>>n>>m;
  graph.resize(n+1);
  visited.assign(n+1,0);
  
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
  }
  
  for(int i=1;i<=n;i++){
    if(!visited[i]) dfs(i);
  }
  
  reverse(topo.begin(),topo.end()); // To get correct order
  
  for(auto ele : topo){
    cout<<ele<<" ";
  }
}
