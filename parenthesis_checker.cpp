/*
   T.C->O(n)
   S.C->O(n)
*/
bool ispar(string x)
    {
        stack<char>s;
        int n=x.size();
        if(n%2==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(x[i]=='(' || x[i]=='[' || x[i]=='{'){
                s.push(x[i]);
            }
             else{
               if(s.empty()){
                   return false;
               }
               if((s.top()=='('&& x[i]==')') ||(s.top()=='{' && x[i]=='}')|| (s.top()=='[' && x[i]==']')){
                     s.pop();
               }
               else{
                    return false;
               }
           }
         
        }
        if(s.empty()){
            return true;
        }
        return 0;
    }