vector<int> nextLargerElement(vector<int> arr, int n){
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            nge[i]=i+1;
            while(nge[i]!=n && arr[i]>=arr[nge[i]]){
                nge[i]=nge[nge[i]];
            }
        }
        //If NGE is not found then nge[i] = n ;
  
        //Uncomment below code if you need actual NGE not index of NGE
        // for(int i=0;i<n;i++){
        //     if(nge[i]==n){
        //         nge[i]=-1;
        //     }else{
        //         nge[i]=arr[nge[i]];
        //     }
        // }
        return nge;
}
