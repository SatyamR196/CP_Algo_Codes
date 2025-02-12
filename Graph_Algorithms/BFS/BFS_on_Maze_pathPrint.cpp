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
vector<vector<state>>par;
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
  par[sNode.F][sNode.S] = {-1,-1} ;
  
  while(!q.empty()){
    state node = q.front();
    q.pop();
    // cout<<node<<" ";
    for(int k=0;k<4;k++){
        int x = node.F+dx[k];
        int y = node.S+dy[k];
        if(check(x,y) && !visited[x][y]){
            q.push({x,y}) ;
            visited[x][y] = 1 ;
            dist[x][y] = dist[x][y]+1 ;
            par[x][y] = node ;
        }
      }
    }
}

void print_charPath(state prev,state curr){
  if(prev.F+1==curr.F){
    cout<<"D";
  }
  else if(prev.F-1==curr.F){
    cout<<"U";
  }
  else if(prev.S+1==curr.S){
    cout<<"R";
  }
  else if(prev.S-1==curr.S){
    cout<<"L";
  }
}

void print_path(state end){
  vector<state>path;
  state curr = end;
  while(curr != make_pair(-1,-1)){
    path.push_back(curr);
    curr = par[curr.F][curr.S] ;
  }
  reverse(path.begin(),path.end());
    
  for(auto v:path){
    cout<<v.F<<" "<<v.S<<endl;
  }
  
  for(int i=1;i<path.size();i++){
    print_charPath(path[i-1],path[i]);
  }
}

int main() 
{ 
  // Taking Input :
  cin>>n>>m ;
  mat.resize(n,vector<char>(m));
  visited.assign(n,vector<int>(m,0));
  dist.assign(n,vector<int>(m,-1));
  par.assign(n,vector<state>(m,{-1,-1}));
  
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
  if(dist[end.F][end.S]==-1){
    cout<<"No valid path exists to reach Final Point";
  }else{
    cout<<"Distance to Final Point = "<<dist[end.F][end.S]<<endl ;
    print_path(end);
  }
}
