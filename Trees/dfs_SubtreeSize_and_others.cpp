//! DFS OF TREE WITH PATH PRINTING Between any two nodes
//& Also finding depth,par,numChild,isLeaf,subTreeSize
// Link : https://onecompiler.com/cpp/43jumdztw
/* Test cases
6 5 5
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
int numChild[100100] ;
int isLeaf[100100] ;
int subTreeSize[100100] ;

void dfs(int cNode, int pNode, int depth){
  dep[cNode] = depth ;
  par[cNode] = pNode ;
  numChild[cNode] = 0 ;
  subTreeSize[cNode] = 1 ;
  
  for(auto child : graph[cNode]){
    if(child!=pNode){
      numChild[cNode]++ ;
      dfs(child,cNode,depth+1);
      subTreeSize[cNode] += subTreeSize[child] ; 
    }
  }
  
  if(numChild[cNode]==0) isLeaf[cNode]=1 ;
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
  int n,st,end;
  cin>>n>>st>>end;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b) ;
    graph[b].push_back(a) ;
  }
  
  dfs(st,0,0) ;
  cout<<subTreeSize[1]<<endl;
  for(int i=1;i<=n;i++){
    //depth,par,numChild,isLeaf,subTreeSize
    cout<<"NODE "<<i<<" : ";
    cout<<dep[i]<<" "<<par[i]<<" "<<numChild[i]<<" "<<isLeaf[i]<<" "<<subTreeSize[i];
    cout<<endl;
  }
  
  printPath(st,end) ;
  
}

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  solve();
}
