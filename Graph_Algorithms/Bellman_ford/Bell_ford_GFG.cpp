vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int>dist(V,1e8);
    int e = edges.size() ;
    dist[src] = 0 ;
    
    for(int i=0;i<V-1;i++){
        // Relex all the edges for V-1 times
        bool flag = false;
        
        for(int j=0;j<e;j++){
            //Relax all the edges for jth pass    
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if(dist[u]==1e8) continue;
            
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w  ;
                flag = true;
            }
            
        }
        
        if(!flag) return dist ;
    }
    
    // Running edge relaxation for Vth time(last time)
    
    for(int j=0;j<e;j++){

        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        
        if(dist[u]==1e8) continue;
        
        if(dist[u]+w < dist[v]){
            vector<int>ans;
            ans.push_back(-1);
            return ans;
        }
            
    }
    
    return dist ;
}
