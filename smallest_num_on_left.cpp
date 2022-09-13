// Similiar to Next smaller element only loop flow change 
// T.c-> O(n)
// S.C-> o(n)

vector<int> leftSmaller(int n, int a[]){
        
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()>=a[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(a[i]);
        }
        return ans;
    }