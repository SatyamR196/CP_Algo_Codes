  // initialize variable to store answer
  int ans=0;
  
  // initialize pointers for initial empty window condition ;
  // first and last both indices are included in window for empty window :
  int first=0,last=-1;
  
  // initialize data-structure for window
  int cnt0=0;
  
  while(first<n){
    //Below loop : window size can increase till we can take more ele inside.
    // Check will tell if we can increment last i.e. take next num in window.
    // bool check = condition to take next num inside window
    while(last+1<n && check(arr,last+1,cnt0,k)){
      last++;
      // Insertion in data-structure

    }
    //Updating ans variable
    ans= ;
    
    if(last<first){//Empty window condition
      first++;
      last=first-1;
    }
    else{
      // Removal from data-structure

      first++;
    }
  }
