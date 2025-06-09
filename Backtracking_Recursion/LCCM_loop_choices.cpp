#include <bits/stdc++.h>
using namespace std;
// LCCM : Level-Choice-Check-Move(i.e. call fxn)
int n,k;
// Global variable to store all possible answer;
vector<vector<int>> ans;
// Global variable to generate answer at each level;
vector<int> cur;
// Alternatively,they can be passed by reference locally also.

bool check(){
    
}
bool check2(){
    
}

rec(int level){
  /* Pruning Case if possible*/
  
  if(/*base case*/){
    if(check()){
      /*Push into ans*/
    }
    return;
  }
  
  for(/*all available choices*/){
    if(check2()){
      // Push choice
      rec(level+1);
      // Pop choice
    }
  }
}
