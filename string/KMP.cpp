// Longest Prefix Suffix(LPS) : lps[i] = length of longest suffix which is equal to prefix till index i of string for which LPS is calculated.
vector<int> get_lps(string str){
  int n = str.length() ;
  vector<int>lps(n+1) ;
  
  int i = 0 , j = -1 ; lps[0] = -1 ;
  while(i<n){
    while(j!= -1 && str[i]!=str[j]) j = lps[j] ;
    j++ ; i++ ;
    lps[i] = j ;
  }
  return lps ; 
}
