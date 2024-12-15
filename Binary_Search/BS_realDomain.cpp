// Framework 1;
// e = (precision or max error allowed) / 100 just to be safe we divide by 100.
// For example, if given precision e<= 1e-6 then we should take e=1e-8 ;
long double low = 0,high=n ;
while(abs(high-low)< e){ 
  long double mid=low+(high-low)/2;
  if(check(mid)){
    high=mid;
  }
  else{
    low=mid;
  }
  long double ans=low+(high-low)/2 ;
}
//-----------------------------------------------------------------------------------------
// Framework 2;
// e = (precision or max error allowed) = (high-low)/(2^r) ,
// here r(No of iterations) is choosen such that e < given limit. 
long double low = 0,high=n ;
for(int i=0; i<r; i++){ 
  long double mid=low+(high-low)/2;
  if(check(mid)){
    high=mid;
  }
  else{
    low=mid;
  }
  long double ans=low+(high-low)/2 ;
}
