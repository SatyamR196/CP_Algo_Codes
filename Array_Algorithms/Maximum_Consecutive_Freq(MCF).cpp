// C++ program to print vector using for
#include <bits/stdc++.h>
using namespace std;

void getMCF(vector<int>& arr , map<int,int>&MCF ){
  if(arr.empty()) return ;
  
  int n = arr.size() ;
  int last = arr[0] ;
  int cnt = 1 ;
  
  for(int i=1 ; i<n ; i++){
    if(arr[i] == last){
      cnt++ ;
    }else{
      MCF[last] = max(MCF[last], cnt) ;
      last = arr[i] ;
      cnt = 1 ;
    }
  }
  
  // for remaing group :
  MCF[last] = max(MCF[last], cnt) ;
  
  
  // Print result
  // for (auto& [key, freq] : MCF) {
  //     cout << "Element " << key << " → Max consecutive freq = " << freq << endl;
  // }
}

int main()
{
    vector<int> v = { 1, 1, 2, 2, 2, 1, 1, 1, 2};
    map<int,int>MCF ;
    getMCF(v,MCF) ;
    return 0;
}
