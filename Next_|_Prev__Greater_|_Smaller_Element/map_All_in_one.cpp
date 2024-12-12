stack<int>st;
unordered_map<int,int> mp;

// for(int i=0 ;i<n;i++){ Next...
// for(int i=n-1 ;i>=0;i--){ Prev...
    // while(!st.empty() && arr[st.top()]<arr[i]){ Greater
    // while(!st.empty() && arr[st.top()]>arr[i]){ Smaller
        mp[arr[st.top()]]= arr[i] ;
        st.pop();
    }
    st.push(i) ;
}

while(!st.empty()){
  mp[arr[st.top()]] = -1 ;
  st.pop();
}
