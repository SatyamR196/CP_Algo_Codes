#include <bits/stdc++.h>
using namespace std;
// Link : https://onecompiler.com/cpp/43m6er2nd
//-
//? PRINT INDUCTION LOGIC :
  //& First define clearly what will be the parameters of the fxn and 
  //& most importantly what this fxn will do as per given parameters.
  //! print(int i,vector<int>v) : print the nums of vector from index i to its end.
  // Then inside of the print fxn, write base case, assume that you already have
  // print fxn ready to use except for the current level(i). So, we can cout<<v[i] 
  // manually then let the fxn print(i+1,v) cout nums from i+1 index to end. In this
  // way the print fxn serves the purpose of printing nums from i index to end.
void print(int i,vector<int>v){
  if(i==v.size()) return ;
  cout<<v[i]<<" " ;
  print(i+1,v) ;
}
//-
//? REVERSE PRINT INDUCTION LOGIC :
  //& First define clearly what will be the parameters of the fxn and 
  //& most importantly what this fxn will do as per given parameters.
  //! print_rev(int i,vector<int>v) : print the nums of vector from its end to i index.
  // Then inside of the print_rev fxn, write base case, assume that you already have
  // print_rev fxn ready to use except for the current level(i). So, you can let the 
  // print_rev(i+1,v) print nums from end to i+1 index , then we cout<<v[i] ; to print
  // the ith num also to fulfill the work of print(i,v) ;
void print_reverse(int i,vector<int>v){
  if(i==v.size()) return ;
  print(i+1,v) ;
  cout<<v[i]<<" " ;
}
//-
int main() 
{
  vector<int> v = {1,2,3,4,5,6} ;
  print(1,v) ;
  print_reverse(1,v) ;
}
