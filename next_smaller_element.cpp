//Approach 1 
// T.C-> O(n*n)
// S.C-> O(1)

 vector<int> help_classmate(vector<int> arr, int n) 
{ 
    vector<int>ans(n);
      for(int i=0;i<n;i++){
          ans[i]=-1;
           for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    ans[i]=arr[j];
                    break;
                }
            }
        }
    return ans;

} 


// Optimise Approach Using Stack
// T.c-> O(n)
// S.C-> O(n)

 vector<int> help_classmate(vector<int> arr, int n) 
{ 
       stack<int>s;
       s.push(-1);
       vector<int>ans(n);
          for(int i=n-1;i>=0;i--){
             int curr=arr[i];
             while(s.top()>=curr){
                 s.pop();
             }
             ans[i]=s.top();
             s.push(curr);
           }
    return ans;
 } 