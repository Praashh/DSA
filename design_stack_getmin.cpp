/* 
    QUESTION ->  Design a stack that supports getMin() in O(1) time and O(1) extra space

    Approach 1st-> T.C -> o(1) and S.C -> O(N)
*/

#include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
     stack<int>s1,s2;
    int mini=INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:

    void push(int data) {
       if(isEmpty()){
           s1.push(data);
           s2.push(data);
       }
        else{
            s1.push(data);
            mini=min(s2.top(),data);
            s2.push(mini);
        }
    }

    int pop() {
       
       if (isEmpty()) {
            return -1;
        }
        int ans=s1.top();
        s1.pop();
        s2.pop();
        return ans;
    }

    int top() {
        if(isEmpty()){
            return -1;
        }
        return  s1.top();
    }

    bool isEmpty() {
        return  s1.empty();
    }

    int getMin() {
        if(isEmpty()){
            return -1;
        }
       return  s2.top();
    }  
};


/*
     Approach 2nd -> calcualte currminimum for each push opeartion and previousminimum for each pop opeartion and 
     store them .
     
      ***** IMPORTANT STEPS ******

     1-> Now, when we need to push a number in the stack, we first need to check if the stack is empty or not. If the stack is empty, we simply push the integer in the stack and make the ‘MINI’ as ‘DATA’. Otherwise,
     if the data is greater than or equal to the top value of the stack, simply push the data into the stack. Else, push 2 * 'DATA' - ‘MINI’ in the stack and update the value of ‘MINI’ as data
     
     2-> For ‘POP’, we need to check if the stack is empty. If the stack is empty, we return ‘-1’. Otherwise, if the top value of the stack is greater than or equal to the ‘MINI’ of the stack, simply pop the top value of the stack, the minimum value here would remain the same. 
     Else, the top is the minimum element and hence we need to retrieve the previous minimum element in the stack. So update the ‘MINI’ = 2 * ‘MINI’ - ‘TOP’.
  

     T.C-> O(1)
     S.C->O(1)
*/

#include<stack>
class SpecialStack {
    // Define the data members.
    stack<int>s;
    int mini;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
      if(isEmpty()){
          s.push(data);
          mini=data;
      }
        else{
            if(data<mini){
                int val=2*data-mini;
                s.push(val);
                mini=data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty()){
            return -1;
        }
        int curr=s.top();
        s.pop();
        if(curr>mini){
            return curr;
        }
        else{
            int prevmin=mini;
            int val=2*mini-curr;
            mini=val;
            return prevmin;
        }
    }

    int top() {
        // Implement the top() function.
        if(isEmpty()){
            return -1;
        }
        if(s.top()<mini){
            return mini;
        }
        else{
            return s.top();
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(isEmpty()){
            return -1;
        }
        return mini;
    }  
};