#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using ll = long long ;
using state = pair<int,int>;
#define F first
#define S second

vector<vector<int>>dist;
vector<vector<int>>num_paths;
vector<vector<char>>mat;
int n,m;
int INF = 1e9;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m && mat[i][j]!='#') return true;
    else return false;
}

void bfs(state sNode){
  queue<state>q;
  q.push(sNode) ;
  dist[sNode.F][sNode.S] = 0 ;
  num_paths[sNode.F][sNode.S] = 1 ;
  
  while(!q.empty()){
    state node = q.front();
    q.pop();
    // cout<<node<<" ";
    for(int k=0;k<4;k++){
        int x = node.F+dx[k];
        int y = node.S+dy[k];
        if(check(x,y)){
          if(dist[x][y] > dist[node.F][node.S] + 1){
            q.push({x,y}) ;
            dist[x][y] = dist[node.F][node.S]+1 ;
            num_paths[x][y] = num_paths[node.F][node.S] ;
          }else if(dist[x][y] == dist[node.F][node.S] + 1){
            num_paths[x][y] += num_paths[node.F][node.S] ;
          }
        }
      }
    }
}

int main() 
{ 
  // Taking Input :
  cin>>n>>m ;
  mat.resize(n,vector<char>(m));
  dist.assign(n,vector<int>(m,INF));
  num_paths.assign(n,vector<int>(m,0));
  
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
  cout<<"Printing Distances :- "<<endl;
  for(int i=0; i<n;i++){
    for(int j=0; j<m; j++){
      cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl<<"Printing num_paths :- "<<endl;
  for(int i=0; i<n;i++){
    for(int j=0; j<m; j++){
      cout<<num_paths[i][j]<<" ";
    }
    cout<<endl;
  }
}
