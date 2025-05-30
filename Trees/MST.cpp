//# 
// Example Link : https://onecompiler.com/cpp/43k93sxkg
//! MINIMUM SPANNING TREE(MST) CODE : USING KRUSHKAL'S ALGO ( Sort EdgesList in ascending order(minHeap) --> using unionFind, merge edges )
//~ For getting maximum spanning Tree : sort edges in descending order of weight(maxHeap) then merge edges
//#
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
//* Rank : It can be height or size of the tree, Rank[x] = Rank[representative(x)] 
//* i.e size of tree where node x is present. We use size of tree as rank.

class unionFind{
  int n, compo_count, *parent, *rank ;
  
  public:
  // Defalut constructor
  unionFind() { }
  //? Custom constructor
  unionFind(int init_nodes){
    n = init_nodes ;
    compo_count = init_nodes ;
    //~ Initialize array parent and rank
    parent = new int[n+1] ;
    rank = new int[n+1] ;
    for(int i=1;i<=n;i++){
      parent[i] = i ;
      rank[i] = 1 ;
    }
  }
  
  //Find(x) --> Return the representative of x in the tree i.e. hightest ancestor(root of tree)
  int find(int x){
    if(x == parent[x] ) return x ;
    parent[x] = find(parent[x]) ;
    return parent[x] ;
  }
  
  //merge(x) --> Return the representative of x in the tree i.e. hightest ancestor(root of tree)
  void merge(int x, int y){
    x = find(x) , y = find(y) ;
    if(x == y) return ;
    
    if(rank[x] < rank[y]){
      parent[x] = y ;
      rank[y] += rank[x] ;
      /// rank[x] = rank[y] ;
    }else{
      parent[y] = x ;
      rank[x] += rank[y] ;
      /// rank[y] = rank[x] ;
    }
    compo_count-- ;
  }
  
  int size(){
    return compo_count ;
  }
  
  int get_rank(int x){// Returns size of component where x is present
    x = find(x) ;
    return rank[x] ;
  }
  
  int get_parent(int x){
    return parent[x] ;
  }
  
  void reset(){
    for(int i=1;i<=n;i++){
      parent[i] = i ;
      rank[i] = 1 ;
    }
  }
  
  void print() {
    cout << "Parent array: ";
    for (int i = 1; i <= n; ++i) {
        cout << parent[i] << " ";
    }
    cout << endl;

    cout << "Rank array:   ";
    for (int i = 1; i <= n; ++i) {
        cout << rank[i] << " ";
    }
    cout << endl;
    
    cout << "Number of components (set_size): " << compo_count << endl;
    
    cout << "Tree : (node , parent[node])"<<endl;
    for (int i = 1; i <= n; ++i) {
        cout << i << " "<< parent[i]<<endl;
    }
  }
};

using ii = pair<int,int>;
// pair<int,ii> edges[200100] ; //~ Taking original graph in form of edge list;
// vector<ii> mst[200100] ; //~ From graph creating a MST
vector<vector<ii>> mst ; //~ From graph creating a MST

void solve(){
  int n,m ;
  cin>>n>>m ;
  mst.resize(n+1) ;
  priority_queue<pair<int,ii>> edges ;
  
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges.push({-w,{u,v}}) ;
    edges.push({-w,{v,u}}) ; //? not required
  }
  
  // Declare unionFind and vars for MST
  unionFind uf(n) ;
  int edge_count = 0 ;
  int mst_cost = 0 ;
  
  debug(edges);
  
  while(!edges.empty()){
    auto pp = edges.top() ;
    edges.pop() ;
    int weight = -pp.F ;
    int u = pp.S.F ;
    int v = pp.S.S ;
    
    if(uf.find(u) != uf.find(v)){
      mst_cost+= weight ;
      uf.merge(u,v) ;
      edge_count ++ ;
      mst[u].push_back({v,weight}) ;
      mst[v].push_back({u,weight}) ;
    }
  }
    
    debug(mst);
    debug(mst_cost,edge_count);
}

int main() 
{
  ios_base::sync_with_stdio(0) ;
  cin.tie(0); cout.tie(0) ;
  solve() ;
  return 0;
}
