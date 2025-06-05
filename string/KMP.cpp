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
