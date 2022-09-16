class Solution{
  private:
   vector<int>nextsmaller(int *arr,int n){
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
    vector<int>prevsmaller(int *arr,int n){
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
   int largestRectangleArea(int *heights,int n) {
        //int n=heights.size();
        
        vector<int>next(n);
        next=nextsmaller(heights,n);
        
        vector<int>prev(n);
        prev=prevsmaller(heights,n);
        int finalarea=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){ // kyu ki mai yaha par indexes calculate kar rha hu isliye mai 
                // next[i]=n; bana deta hu because next[i] wo n par hi -1 hoga 
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int area=l*b;
            finalarea=max(area,finalarea);
        }
        return finalarea;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        // calculate area for first row 
        int area=largestRectangleArea(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                
                // Update row by adding previous row's value
                if(M[i][j]!=0){
                M[i][j]=M[i][j]+M[i-1][j];
                }
                else
                M[i][j]=0;
            }
            area=max(area,largestRectangleArea(M[i],m));
        }
        return area;
    }
};