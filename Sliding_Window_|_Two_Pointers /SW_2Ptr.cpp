// Fixed sliding window using 2 Pointers
    int first=0,last=0;
    int wSize;
    while(last<n){
        if(last-first+1 < wSize){
            // Thing to do when current window size < desired window size.
            last++;
        }
        else{
            // Thing to do when current window size == given wSize.
            // Step 2a: Add new element (at high index) to the window for the current window.
            // Step 2b: Calculate the answer based on the elements in the window.
            // Step 2c: Remove the oldest element (at first index) from the window for the next window.
            first++;last++;
        }
  }
