#include<bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using state = pair<int,int>;
using ll = long long ;
#define endl "\n"
//#define int long long
int mod = 1e9+7 ;

#define F first
#define S second
vvc mat;
vvi visited;
vector<int>perimeter;
int n,m;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m && mat[i][j]=='#') return true;
    else return false;
}

void dfs(state node,int c_no){
    visited[node.F][node.S] = c_no;
    for(int k=0;k<4;k++){
        int x = node.F+dx[k];
        int y = node.S+dy[k];
        if(check(x,y) && !visited[x][y]){
            dfs({x,y},c_no) ;
        }
    }
}

void solve(){
    cin>>n>>m;
    mat.resize(n,vector<char>(m));
    visited.assign(n,vector<int>(m,0));
    perimeter.assign(n*n,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j] ;
        }
    }

    int c_no = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && mat[i][j]=='#'){
                dfs({i,j},++c_no);
            }
        }
    }

    // debug(visited);
    vector<int>compo_size(n*n) ;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]){
                compo_size[visited[i][j]]++ ;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}