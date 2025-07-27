// Kadane's Algo is used to find the max subArr Sum in an array and we can modify it to find that subArr as well :
// Solution Link(Without subArr finding) : https://onecompiler.com/cpp/43pku7grw
int maxSum = INT_MIN ;
int curr_sum = 0 ;

for(int i=0 ; i<n ; i++){
    curr_sum+= arr[i] ;
    maxSum = max(maxSum,curr_sum) ;
    if(curr_sum<0) curr_sum = 0 ;
}

// Solution Link(with max subArr finding) : https://onecompiler.com/cpp/43pk227tw
for(int i=0 ; i<n ; i++){
    if(curr_sum == 0 ) newSt = i ; //? for printing solution
    curr_sum+= arr[i] ;
    
    if(curr_sum > maxSum){
        maxSum = curr_sum ;
        ansSt = newSt ; //? for printing solution
        ansEnd = i ; //? for printing solution
    }
    if(curr_sum<0) curr_sum = 0 ;
}
    
cout<<maxSum<<endl ;
cout<<ansSt<<" "<<ansEnd<<endl ;
