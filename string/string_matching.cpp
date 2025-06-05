//! CODE FOR KMP ALGO for string matching
#include <bits/stdc++.h>
using namespace std;

vector<int> get_kmp(string str){
  int n = str.length() ;
  vector<int>kmp(n+1) ;
  
  int i = 0 , j = -1 ; kmp[0] = -1 ;
  while(i<n){
    while(j!= -1 && str[i]!=str[j]) j = kmp[j] ;
    j++ ; i++ ;
    kmp[i] = j ;
  }
  return kmp ; 
}

vector<int> find(string pattern, string text){
  //* Return the starting indexs of all matching pattern
  string str = pattern + "#" + text ;
  vector<int> lps = get_kmp(str) ;
  vector<int>ans;
  
  int n1 = pattern.length() ;
  int n2 = text.length() ;
  
  for(int i=0; i<lps.size() ; i++){
    if(lps[i] == n1) ans.push_back(i-n1-(n1)-1) ;
  }
  
  return ans ;
  
}

int main() 
{
  string pattern,str ; 
  cin>>pattern>>str ;
  
  // auto kmp = get_kmp(str) ;
  vector<int>findIndex = find(pattern,str) ;
  
  for(auto ele : findIndex ){
    cout<<ele<<" ";
  }
}
