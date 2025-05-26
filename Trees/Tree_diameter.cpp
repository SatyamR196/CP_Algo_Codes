//#                                                                                   
//! FINDING TREE DIAMETER USING 2 DFS METHOD
//? Pick a random node, do dfs, get the farthest node that will be one end of diameter
//? then from that end again repeat the process then this time you will get other end also.
//#                                                                                   
/* TEST CASES
6
1 2
1 3
3 4 
3 5
2 6
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100100] ;
int dep[100100] ;
int par[100100] ;

void dfs(int cNode, int pNode, int depth){
  dep[cNode] = depth ;
  par[cNode] = pNode ;
  
  for(auto child : graph[cNode]){
    if(child!=pNode){
      dfs(child,cNode,depth+1);
    }
  }
}

void printPath(int st, int end){
  int cNode = end;
  int parent = par[cNode] ;
  stack<int>path;
  
  if(st==end){
    cout<<st<<endl;
    return;
  }
  
  path.push(end);
  
  while(parent!= st){
    path.push(parent);
    parent=par[parent] ;
  }
  
  path.push(st);
  
  while(!path.empty()){
    cout<<path.top()<<" ";
    path.pop();
  }
}

void solve(){
  int n;
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b) ;
    graph[b].push_back(a) ;
  }
  
  //~ Choose any random node as diameter start and do dfs to get all distances from start
  int diaSt = 1;
  dfs(diaSt,0,0) ;
  //? Now Iterate over all distances and find farthest node, that will be one end of dia.
  for(int i=1;i<=n;i++){
    if(dep[i]>dep[diaSt]) diaSt = i ;
  }
  //& Then from diaSt do dfs taking it as root node and find all distances.
  int diaEnd = diaSt ;
  dfs(diaSt,0,0) ;
  //? Now Iterate over all distances and find farthest node, that will be other end of dia.
  for(int i=1;i<=n;i++){
    if(dep[i]>dep[diaEnd]) diaEnd = i ;
  }
  
  cout<<"Diameter = "<<dep[diaEnd]<<endl;
  cout<<"Diameter Path : ";
  printPath(diaSt,diaEnd) ;
  
}

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  solve();
}
