vector<int> NGE(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[idx]){
                nge[st.top()]=nums[idx];
                // nge[st.top()]=idx; //If index of NGE is needed;
                st.pop();
            }
            st.push(idx);
        }    
        return nge;
}
