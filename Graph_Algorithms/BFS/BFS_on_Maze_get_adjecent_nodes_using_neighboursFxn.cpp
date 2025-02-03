// '#' --> Wall, '.' --> open space , 'S' --> staring point , 'F' --> final point
#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using ll = long long ;
using state = pair<int,int>;

#define F first
#define S second

vector<vector<int>>visited;
vector<vector<int>>dist;
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
  visited[sNode.F][sNode.S] = 1 ;
  dist[sNode.F][sNode.S] = 0 ;
  
  while(!q.empty()){
    state node = q.front();
    q.pop();
    // cout<<node<<" ";
    for(auto ele : neighbours(node)){
      if(!visited[ele.F][ele.S]){//If it is not already pushed into queue
        q.push(ele) ;
        visited[ele.F][ele.S] = 1 ;
        dist[ele.F][ele.S] = dist[node.F][node.S]+1 ;
      }
    }
  }
}

int main() 
{ 
  // Taking Input :
  cin>>n>>m ;
  mat.resize(n,vector<char>(m));
  visited.assign(n,vector<int>(m,0));
  dist.assign(n,vector<int>(m,-1));
  
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
  cout<<"Distance to Final Point = "<<dist[end.F][end.S]<<endl ;
}
