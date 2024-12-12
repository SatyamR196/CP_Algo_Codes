// Creation of prefix max/min and suffix max/min arrarys
// pMax[i] = max element of left of i
// pMin[i] = min element of left of i
// sMax[i] = max element of right of i
// sMin[i] = min element of right of i
int pMax[n],pMin[n],sMax[n],sMin[n] ;

for(int i=0;i<n;i++){
  pMax[i]=arr[i];
  if(i) pMax[i] = max(pMax[i-1],arr[i]);
}
for(int i=0;i<n;i++){
  pMin[i]=arr[i];
  if(i) pMin[i] = min(pMin[i-1],arr[i]);
}
for(int i=n-1;i>=0;i--){
  sMax[i]=arr[i];
  if(i<n-1) sMax[i] = max(sMax[i+1],arr[i]);
}
for(int i=n-1;i>=0;i--){
  sMin[i]=arr[i];
  if(i<n-1) sMin[i] = min(sMin[i+1],arr[i]);
}
