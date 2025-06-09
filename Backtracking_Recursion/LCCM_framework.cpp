// LCCM : Level-Choice-Check-Move(i.e. call fxn)
// Level = A pointer which will help us in exploring all the solution space, for arr,vector,string --> level = index i, for set,map --> level = iterator *it
// Choice = For each level what choices you can make e.g. move 1/2/3 steps in n-steps problem, use '(' or ')' in parenthesis generation problem.
// Check = For each of your choice, check if it's valid as per the constraint, e.g. in n-steps problem, you can't choose 3 step-jump if curr_step+3 > n
// Move = If check is true, then insert choice into container and call fxn itself to move to next level, don't forget to remove choice once you come out.

#include <bits/stdc++.h>
using namespace std;
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
