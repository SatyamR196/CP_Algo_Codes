int search(vector<int>& nums,int target) {
        int index= upper_bound(nums.begin(),nums.end(),target)-nums.begin(); // if array is sorted in non decreasing order
        int index= upper_bound(nums.begin(),nums.end(),target,greater<int>())-nums.begin(); // if array is sorted in non increasing order
        if(index==0) return -1;
        if(nums[index-1]==target){
            return index-1;
        }else{
            return -1;
        }
}
