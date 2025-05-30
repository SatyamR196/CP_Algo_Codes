#include <bits/stdc++.h>
using namespace std;

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
