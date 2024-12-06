for(int i=0;i<n;i++){
      
//Action to be performed always like insertion in window. 
      
      if(i-wSize+1>=0){
      
      //Main actions to be performed in every window once window is of desired size like printing sum of window elements.
      
      //Remove the effect of first window element for next slide e.g. deletion of element from bag.
      
      }
}

// Example 1 : where bag is a custom data structure supporting insert,remove,getMax fxn;
for(int i=0;i<n;i++){ 
      bag.insert(arr[i]);
      if(i-wSize+1>=0){
            cout<<bag.getMax()<<" "; 
            bag.remove(arr[i-wSize+1]);  
      } 
}
// Example 2 : Counting 0s and 1s in every window;
for(int i=0;i<n;i++){
  arr[i]==0 ? count0++ : count1++ ;
  if(i-wSize+1>=0){
      cout<<"count 0 = "<<count0<<" , "<<"count 1 = "<<count1<<endl; 
      arr[i]==0 ? count0-- : count1-- ;
  } 
}
