/* Approach ;-
    Step 1- calculate Area in right side through nextsmaller function
    step 2- calculate Area in left side through prevsmaller function

    Note 1: The Length of rectangle is element like heights[i] and Width calculates by nextsmaller and prevsmaller
    function  int b=next[i]-prev[i]-1; and before calculating this check next[i]!=-1 if yes then do next[i]=n;

    Note 2:  In nextsmaller and prevsmaller function always remember store the index not value 
 */
 vector<int>nextsmaller(vector<int>&arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){ 
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
        
    }
    vector<int>prevsmaller(vector<int>&arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){
                s.pop();
            }
        ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        vector<int>next(n);
        next=nextsmaller(heights,n);
        
        vector<int>prev(n);
        prev=prevsmaller(heights,n);
        
        int area=INT_MIN;
        
        for(int i=0;i<n;i++){
           int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
           int b=next[i]-prev[i]-1;
           int newarea=l*b;
           area=max(area,newarea);
        }
        return area;
    }   