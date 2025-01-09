#include <bits/stdc++.h>
using namespace std;
// LCCM : Level-Choice-Check-Move(i.e. call fxn)
int n,k;
// Global variable to store all possible answer;
vector<string> ans;
// Global variable to generate answer at each level;
string cur;
// Alternatively,they can be passed by reference locally also.

bool check_valid(string s){
    
}

void rec(int level){ // decided [level...n] with last choices leading to cur.
    //The word “prune” means to reduce something by removing things that are not necessary.
    // pruning case :
    if(0) return ;
    // base case :
    if(level==n){
        if(check_valid(cur)){
            //save answer in global variable
        }
        return;
    }
    // recursive case :
    // choice 1:
    if(1){ // check
        // Do something to choose option 1
        // Move(CALL FXN) 
        // Undo it's effect
    }
    // choice 2:
    if(1){
        // Do something to choose option 2
        // Move(CALL FXN) 
        // Undo it's effect
    }
    // using loop this can be done for n choices also.

}