#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph ;
vector<int>visited;
// 0 --> not visited , 1,2,3... --> component no. where node lies
int n,m;

void dfs(int node,int c_no){
  visited[node]= c_no;
  for(auto ele : graph[node]){
    if(!visited[ele]){
      dfs(ele,c_no);
    }
  }
}

int main() 
{  
  // Taking Input :
  cin>>n>>m ;
  graph.resize(n+1);
  visited.assign(n+1,0);
  
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  // Doing DFS
  int c_no = 0 ;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      dfs(i,++c_no);
    }
  }
  
  // Making Component Size Vector --> Component No. : It's size
  vector<int>compo_size(n+1,0);
  for(auto ele : visited){
    if(ele==0) continue;
    compo_size[ele]++;
  }

}
