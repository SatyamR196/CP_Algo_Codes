bool check(vector<int>arr,int mid,int key){
  int n=arr.size();
  if(arr[mid]) return true;
  else return false;
}
//Just change the check fxn as per the question.
int main() 
{   
    int low=0, high=n-1, ans=n;
    while(low<=high){
      int mid=low+(high-low)/2;
      
      if(check(arr,mid,key)){
        ans=mid;
        high=mid-1;
      }else{
        low=mid+1;
      }
    }
    cout<<ans<<endl;
}
