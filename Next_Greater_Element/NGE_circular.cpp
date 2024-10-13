vector<int> NGE(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n,-1);
        stack<int>st;
        int idx=0;
        for(int i=0;i<2*n;i++){
            idx=i%n;
            while(!st.empty() && nums[st.top()]<nums[idx]){
                nge[st.top()]=nums[idx];
                // nge[st.top()]=idx; //If index of NGE is needed;
                st.pop();
            }
            if(i<n) st.push(idx);
        }    
        return nge;
}
