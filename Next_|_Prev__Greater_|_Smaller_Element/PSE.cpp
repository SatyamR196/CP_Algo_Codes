stack<int>st;
vector<int>nse(n,-1);

for(int i=n-1 ;i>=0 ;i--){
    while(!st.empty() && arr[st.top()]>arr[i]){
        nse[st.top()] = arr[i] ;
      // If one want indices of PSE then nse[st.top()] = i ;
        st.pop();
    }
    st.push(i) ;
}
