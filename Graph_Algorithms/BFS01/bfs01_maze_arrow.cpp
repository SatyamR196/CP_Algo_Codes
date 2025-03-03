#include<bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using ll = long long ;
#define endl "\n"
//#define int long long
int mod = 1e9+7 ;
int INF = 1e9 ;

int n,m;
using state = pair<int,int>;
#define F first
#define S second

bool check(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

vector<vector<int>>mat;
vector<vector<int>>dist;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs01(state sNode){
    deque<state>q;
    q.push_back(sNode) ;
    dist[sNode.F][sNode.S] = 0 ;
    
    while(!q.empty()){
        state cNode = q.front();
        q.pop_front();
        for(int k=0;k<4;k++){
            int x = cNode.F + dx[k];
            int y = cNode.S + dy[k];
            if(!check(x,y)) continue;
            int weight = (k + 1 == mat[cNode.F][cNode.S]) ? 0 : 1;

            // if(dx[k]==1 & mat[cNode.F][cNode.S]== 3){
            //     weight = 0;
            // }
            // else if(dx[k]==-1 & mat[cNode.F][cNode.S]== 4){
            //     weight = 0;
            // }
            // if(dy[k]==1 & mat[cNode.F][cNode.S]== 1){
            //     weight = 0;
            // }
            // else if(dy[k]==-1 & mat[cNode.F][cNode.S]== 2){
            //     weight = 0;
            // }
            // else{
            //     weight = 1;
            // }

            if(dist[x][y] > dist[cNode.F][cNode.S] + weight){
              
                dist[x][y] = dist[cNode.F][cNode.S] + weight ;
                if(weight==0) q.push_front({x,y});
                else q.push_back({x,y});
              
            }
        }
    }

}

void solve(){
    cin>>n>>m;
    mat.resize(n,vector<int>(m));
    dist.assign(n,vector<int>(m,INF));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    bfs01({0,0}) ;
    cout<<dist[n-1][m-1]<<endl;
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




