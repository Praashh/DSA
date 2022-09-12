int print2largest(int arr[], int n) {
	    // code here
        int maxi=INT_MIN,second_maxi=-1;
        for(int i=0;i<n;i++){
             if(arr[i]>maxi)maxi=arr[i];
        }
               
         for(int i=0;i<n;i++){
             if(arr[i]>second_maxi&&arr[i]<maxi)
                  second_maxi=arr[i];
            }
          if(second_maxi==maxi) 
             return -1;
        
          return second_maxi;

	}