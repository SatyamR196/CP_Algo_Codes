#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using ll = long long ;
using state = pair<int,int>;
//---- Debugger ------------------------------------------//
#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
#include <bits/stdc++.h>
#define cerr cout
namespace __DEBUG_UTIL__
{
    using namespace std;
    /* Primitive Datatypes Print */
    void print(const char *x) { cerr << x; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    // void print(signed short int x) { cerr << x; }
    // void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    // void print(signed long int x) { cerr << x; }
    // void print(unsigned long int x) { cerr << x; }
    // void print(signed long long int x) { cerr << x; }
    // void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> v)
    { /* Overloaded this because stl optimizes vector<bool> by using
          _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename T>
    void print(vector<vector<T>> mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(tuple<Args...> t);
    template <typename... T>
    void print(priority_queue<T...> pq);
    template <typename T>
    void print(stack<T> st);
    template <typename T>
    void print(queue<T> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T &&x)
    {
        /*  This works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        cerr << '{';
        for (auto &&i : x)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename T>
    void print(vector<vector<T>> mat)
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x)
    {
        cerr << '(';
        print(x.first);
        cerr << ',';
        print(x.second);
        cerr << ')';
    }
    template <typename T, size_t N>
    struct Tuple
    {
        static void printTuple(T t)
        {
            Tuple<T, N - 1>::printTuple(t);
            cerr << ",", print(get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1>
    {
        static void printTuple(T t) { print(get<0>(t)); }
    };
    template <typename... Args>
    void print(tuple<Args...> t)
    {
        cerr << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        cerr << ")";
    }
    template <typename... T>
    void print(priority_queue<T...> pq)
    {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename T>
    void print(stack<T> st)
    {
        int f = 0;
        cerr << '{';
        while (!st.empty())
            cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        cerr << "}";
    }
    template <typename T>
    void print(queue<T> q)
    {
        int f = 0;
        cerr << '{';
        while (!q.empty())
            cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        cerr << "}";
    }
    /* Printer functions */
    void printer(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        /* Using && to capture both lvalues and rvalues */
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(head);
        if (sizeof...(tail))
            cerr << " ||", printer(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
    /* PrinterArr */
    void printerArr(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t ind = 0;
        for (; names[ind] and names[ind] != ','; ind++)
            cerr << names[ind];
        for (ind++; names[ind] and names[ind] != ','; ind++)
            ;
        cerr << " = {";
        for (size_t i = 0; i < N; i++)
            cerr << (i ? "," : ""), print(arr[i]);
        cerr << "}";
        if (sizeof...(tail))
            cerr << " ||", printerArr(names + ind + 1, tail...);
        else
            cerr << "]\n";
    }
}
#ifndef ONLINE_JUDGE
// #ifdef ONLINE_JUDGE  
//uncomment to ignore debug statments while run on sample in submit it is already ignored.
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif
#endif
//--------------------------------------------------- //
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
    for(auto ele : neighbours(node)){
      if(!visited[ele.F][ele.S]){//If it is not already pushed into queue
        q.push(ele) ;
        visited[ele.F][ele.S] = 1 ;
        dist[ele.F][ele.S] = dist[node.F][node.S]+1 ;
        par[ele.F][ele.S] = node ;
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
