stack<int>st;
unordered_map<int,int> nse;

for(int i=0 ;i<n;i++){
    while(!st.empty() && st.top()>arr[i]){
        nse[st.top()] = arr[i] ;
        st.pop();
    }
    st.push(arr[i]) ;
}

while(!st.empty()){
  nse[st.top()] = -1 ;
  st.pop();
}
