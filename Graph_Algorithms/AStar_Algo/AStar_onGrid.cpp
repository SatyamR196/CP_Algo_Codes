// Q : Given the grid, grid[x][y] = dist to reach that cell, find the minimum 
// distance and print the shortest path as well to reach from start to end.

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long
int INF = 1e9 ;
using ii = pair<int,int> ;
int n,m ;
vector<vector<int>>grid ;
vector<vector<int>>visited ;
vector<vector<int>>dist ;
vector<vector<ii>>parent ;

#ifndef ONLINE_JUDGE
#include "D:\C++ DSA\CP\Programs\Templates\template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define F first
#define S second

int dx[] = {1,0,-1,0} ;
int dy[] = {0,1,0,-1} ;

int Euclid_dist(ii st, ii end){
    return sqrt(pow(abs(st.F-end.F),2) + pow(abs(st.S-end.S),2)) ;
}

int manhattan(ii a, ii b) {
    return abs(a.F - b.F) + abs(a.S - b.S);
}

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void AStar(ii st, ii end){
    priority_queue<pair<int,ii>> pq ; // dist , node(x,y)
    pq.push({-0,st}) ;
    dist[st.F][st.S] = 0 ;

    while(!pq.empty()){
        auto cNode = pq.top() ;
        // debug(cNode);
        pq.pop() ;
        int x = cNode.S.F ;
        int y = cNode.S.S ;
        int cDist = dist[x][y] ; //? != cNode.F because cNode.F is dist f not actual dist.

        //checks
        if(visited[x][y]) continue;
        else visited[x][y] = 1 ;
        if(x==end.F && y==end.S) break ; 

        // explore neighbour , edge relex
        for(int k=0 ; k<4 ; k++){
            int nx = x+dx[k] ;
            int ny = y+dy[k] ;
            if(!isValid(nx,ny)) continue ;

            int neigh_Dist = cDist + grid[nx][ny] ; // dist of neigh from st
            // int h = Euclid_dist({nx,ny},end); // heristic dist from end (goal)
            int h = manhattan({nx,ny},end); // heristic dist from end (goal)
            int f = neigh_Dist + h ; // final dist to be used for A*.
            // debug(neigh_Dist,h,f) ;

            if(dist[nx][ny] > neigh_Dist){
                dist[nx][ny] = neigh_Dist ;
                parent[nx][ny] = {x,y} ;
                pq.push({-f,{nx,ny}}) ;
            }
        }
    }

}

void solve(){
    cin>>n>>m ;
    grid.resize(n,vector<int>(m)) ;
    parent.resize(n,vector<ii>(m)) ;
    visited.assign(n,vector<int>(m,0)) ;
    dist.resize(n,vector<int>(m,INF)) ;
    // grid[x][y] is the edge cost to move into cell (x, y) ;
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<m ; j++){
            cin>>grid[i][j] ;
        }
    }

    ii st = {1,2}, end = {3,4} ;
    AStar(st,end) ;

    ii temp = end ;
    vector<ii>path ;
    while(temp != st){
        path.push_back({temp}) ;
        temp = parent[temp.F][temp.S] ;
    }
    path.push_back(st) ;
    reverse(path.begin(),path.end()) ;
    cout<<"Shortest Path :- "<<endl ;
    for (auto [px, py] : path){
        cout << "(" << px << "," << py << ") ";
    }
    cout << "\n";
    
    cout<<"Dist to End From Start : "<<dist[end.F][end.S]<<endl ;
    debug(dist) ;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}
