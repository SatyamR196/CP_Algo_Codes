// This can also be used to dectect cycle in DAG, if(num of ele in topo != n ) isCycle == true ;
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>graph;
vector<int>indeg;
vector<int>topo;

void Kahn_topo(){
  // priority_queue used for topo in lexicographical order
  priority_queue<int,vector<int>,greater<int>>q ; // min_heap
  for(int i=1;i<=n;i++){
    if(indeg[i]==0) q.push(i);
  }
  
  while(!q.empty()){
    int cNode = q.top() ; 
    q.pop() ;
    for(auto ele : graph[cNode]){
      indeg[ele]--;
      if(indeg[ele]==0) q.push(ele) ;
    }
    topo.push_back(cNode) ;
  }
}

int main() 
{
  cin>>n>>m;
  graph.resize(n+1);
  indeg.resize(n+1);
  
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    indeg[b]++;
  }
  
  Kahn_topo();
  
  for(auto ele : topo){
    cout<<ele<<" ";
  }
}
