// Question : Generate all valid parenethesis string containing only '(',')' of length n and max-depth=k
#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<string> ans;

bool check_valid(string s){
    int depth = 0;
    int max_depth = 0;
    for(auto v:s){
        if(v=='(')depth++;
        else depth--;
        max_depth = max(max_depth,depth);
        if(depth<0)return 0;
    }
    if(depth==0 && max_depth==k)return 1;
    else return 0;
}

string cur;
void rec(int level){ // decided [level...n] with last choices leading to cur.
    // base case
    // cout<<level<<" "<<cur<<endl;
    if(level==n){
        if(check_valid(cur)){
            ans.push_back(cur);
        }
        return;
    }
    // recursive case
    
    // choice 1: open
    if(1){ // check
        // move 
        cur+='(';
        rec(level+1);
        cur.pop_back();
    }
    
    // choice 2: close
    if(1){
        cur+=')';
        rec(level+1);
        cur.pop_back();
    }
    
    return;
}

int main(){
    cin>>n>>k;
    rec(0);
    cout<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v<<endl;
    }
}