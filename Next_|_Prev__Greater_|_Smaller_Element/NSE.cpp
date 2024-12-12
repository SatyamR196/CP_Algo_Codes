// int n=6;
// int arr[n]={3,5,5,1,6,2} ;
stack<int>st;
vector<int>nse(n,-1);

for(int i=0 ;i<n;i++){
    while(!st.empty() && arr[st.top()]>arr[i]){
        nse[st.top()] = i ; 
        // If one wants actual NSE not index then... nse[st.top()] = arr[i] ;
        st.pop();
    }
    st.push(i) ;
}
