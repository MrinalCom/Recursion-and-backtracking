int prev2=0,prev=1;
        for(int i=2;i<=n+1;i++){
          //assign to curri value(of previous 2 values) 
          int curri = prev+prev2 ; 
          //update prev2 and prev 
          prev2=prev;
          prev=curri; 
       }
       return prev;
    }
 };
