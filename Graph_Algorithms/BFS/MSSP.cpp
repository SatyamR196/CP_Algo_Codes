using state = pair<int,int>
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<vector<int>>visited;

void bfs_MSSP(vector<state>sNode){
  queue<state>q;
  for(auto node : sNode){
    q.push(node) ;
    visited[node.F][node.S] = 1 ;
    distM[node.F][node.S] = 0 ;
  }
  
  while(!q.empty()){
    state node = q.front();
    q.pop();
    for(int k=0;k<4;k++){
        int x = node.F+dx[k];
        int y = node.S+dy[k];
        if(check(x,y) && !visited[x][y]){
            q.push({x,y}) ;
            visited[x][y] = 1 ;
            distM[x][y] = distM[node.F][node.S] + 1 ;
        }
    }
  }
}
