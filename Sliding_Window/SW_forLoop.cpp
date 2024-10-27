for(int i=0;i<n;i++){
      if(arr[i]==0)cnt0++;
      else cnt1++;
      
      if(i-wSize>=0){
         if(arr[i-wSize]==0) cnt0--;
         else cnt1--;
      }
      if(i-wSize>=-1){
        //inside here goes any action you want to
        //perform for every window
      }
}
