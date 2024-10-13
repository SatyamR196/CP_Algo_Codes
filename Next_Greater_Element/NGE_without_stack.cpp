vector<int> nextLargerElement(vector<int> arr, int n){
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            nge[i]=i+1;//doing this we assume that next element is our NGE
            while(nge[i]!=n && arr[i]>=arr[nge[i]]){// but if this conditon is true then our assumption is wrong
                //hence the current element says my NGE = my next element NGE ;
                //This continues till current element got it's actual NGE and while loop exits.
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
