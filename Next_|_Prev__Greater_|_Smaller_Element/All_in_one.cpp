// This code can be used to find NGE,PGE,NSE and PSE, just choose appropriate pair of for_loop and while_loop and uncomment them.
  stack<int>st;
  vector<intv(n,-1);

// for(int i=0 ; i<n ;i++){ Next...
// for(int i=n-1 ;i>=0 ;i--){ Prev...
    // while(!st.empty() && arr[st.top()]<arr[i]){ Greater
    // while(!st.empty() && arr[st.top()]>arr[i]){ Smaller
        v[st.top()]= arr[i] ;
        st.pop();
    }
    st.push(i) ;
}