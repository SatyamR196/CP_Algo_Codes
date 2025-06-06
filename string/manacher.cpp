// LINK : https://onecompiler.com/cpp/43kxdgu2d
#include<bits/stdc++.h>
using namespace std;

vector<int> manacher(string s){
  int n = s.length() ;
  string t = "";
  for(auto c: s) {
      t += string("#") + c;
  }
  t+="#" ;
  
  s = t ;
  n = s.length() ;
  cout<<t<<endl ;
  
  vector<vector<int>> p(2,vector<int>(n,0)) ;
  for(int z=0,l=0,r=0;z<2;z++,l=0,r=0){
    for(int i=0;i<n;i++)
    {
      if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
      int L=i-p[z][i], R=i+p[z][i]-!z ;
      while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
      if(R>r) l=L,r=R;
    }
  }
  return p[1] ;
}

int main()
{
  cout << "Hello, World!"<<endl ;
  string str ;
  cin>>str ;
  auto man_arr = manacher(str) ;
  
  int centre = 0 , radius = 0 ;
  int longestP = INT_MIN ;
  
  for(int i=0 ;i<man_arr.size() ; i++){
    if(man_arr[i]>longestP){
      centre = i ;
      longestP = man_arr[i] ;
    }
  }
  int st,end ;
  st = (centre - longestP/2 -1)/2;
  end = (centre + longestP/2 +1)/2;
  cout<<"centre of Longest Palindrome : "<<centre<<endl;
  cout<<"Lenth of longest Palindrome : "<<longestP<<endl;
  cout<<"Starting index of Palindrome : "<<st<<endl;
  cout<<"Starting index of Palindrome : "<<end<<endl;
  return 0 ;
}
