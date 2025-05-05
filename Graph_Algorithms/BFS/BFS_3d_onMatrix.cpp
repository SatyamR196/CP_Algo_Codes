// Qs : Find the minimum distance to 'F' node for <= k wall breaks allowed;
// OneCompiler Link : https://onecompiler.com/cpp/43guf3nu4
/* TEST CASE
6 6 2 
S.#...
..#...
#.#.#.
....#.
####..
F.....
*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second


using ii = pair<int,int>;
using state = pair<pair<int,int>,int>;
int INF = 1e9;

int dx[] = {1,0,-1,0} ;
int dy[] = {0,1,0,-1} ;

int n,m,k;
vector<vector<vector<int>>>dist;
vector<vector<char>>mat;

// bool check(int x, int y){
//   return (x>=0 && x<n && y>=0 && y<m) ;
// }
bool check(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m ) return true;
    else return false;
}

void bfs_MS(state st){

  dist[st.F.F][st.F.S][st.S] = 0 ;
  queue<state>q;
  q.push(st) ;
  
  while(!q.empty()){
    state curr = q.front();
    q.pop();
    //explore neighbours
    for(int i=0; i<4 ; i++){
      
      int x = curr.F.F + dx[i] ; 
      int y = curr.F.S + dy[i] ; 
      
      if(check(x,y)){
        int z = curr.S ;
        int w = mat[x][y] == '#' ? 1 : 0 ;
        z += w ;
        if(z>k) continue ;
        
        if(dist[x][y][z] > dist[curr.F.F][curr.F.S][curr.S] + 1){
          dist[x][y][z] = dist[curr.F.F][curr.F.S][curr.S] + 1 ;
          q.push({{x,y},z}) ;
        }
      }
      
    }
  }
}

void solve(){
  cin>>n>>m>>k;
  mat.resize(n,vector<char>(m));
  dist.assign(n,vector<vector<int>>(m,vector<int>(k+1,INF)));
  ii st,en;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>mat[i][j] ;
      if(mat[i][j]=='S'){
        st = {i,j} ;
      }
      else if(mat[i][j]=='F'){
        en = {i,j} ;
      }
    }
  }
  
  bfs_MS({st,0});
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<mat[i][j]<<" " ;
    }
    cout<<endl;
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<dist[i][j][0]<<" " ;
    }
    cout<<endl;
  }
  cout<<endl;
  int minDist = INF ;
  
  for(int wb=0 ; wb <= k ; wb ++){
    minDist = min(minDist, dist[en.F][en.S][wb]) ;
  }
  
  cout<<"Min distance to 'F' for <=k wall break = "<<minDist<<endl;
  
}

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  solve();
}
