#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using ll = long long ;
using state = pair<int,int>;

#define F first
#define S second

map<state,bool>visited;
map<state,int>dist;
vector<vector<char>>mat;
int n,m;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m && mat[i][j]!='#') return true;
    else return false;
}

vector<state> neighbours(state node){
  vector<state> v;
  for(int k=0;k<4;k++){
    int x = node.F+dx[k];
    int y = node.S+dy[k];
    if(check(x,y)){
      v.push_back({x,y});
    }
  }
  return v;
}

void bfs(state sNode){
  queue<state>q;
  q.push(sNode) ;
  visited[sNode] = 1 ;
  dist[sNode] = 0 ;
  
  while(!q.empty()){
    state node = q.front();
    q.pop();
    // cout<<node<<" ";
    for(auto ele : neighbours(node)){
      if(!visited[ele]){//If it is not already pushed into queue
        q.push(ele) ;
        visited[ele] = 1 ;
        dist[ele] = dist[node]+1 ;
      }
    }
  }
}

int main() 
{ 
  // Taking Input :
  cin>>n>>m ;
  mat.resize(n,vector<char>(m));
  // visited.assign(n*m,);
  // dist.assign(n,vector<int>(m,-1));
  
  state st,end;
  // Taking input matrix
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>mat[i][j] ;
      if(mat[i][j]=='S') st={i,j};
      else if(mat[i][j]=='F') end={i,j};
    }
  }

  bfs(st);
  // for(auto ele : visited){
  //   cout<<"{"<<ele.F.F<<","<<ele.F.S<<"} : ";
  //     cout<<ele.S<<" ";
  //   cout<<endl;
  // }
  // cout<<"Distance"<<endl;
  // for(auto ele : dist){
  //   cout<<"{"<<ele.F.F<<","<<ele.F.S<<"} : ";
  //     cout<<ele.S<<" ";
  //   cout<<endl;
  // }
  cout<<"Distance to Final Point = "<<dist[end]<<endl ;
}
