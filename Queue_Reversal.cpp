// Question -> reverse a Queue
// Approach 1-> USing Stack 
// T.C-> O(N) AND S.C->O(N)

queue<int> rev(queue<int> q)
{
    stack<int>s;
    queue<int>ans;
    // push all the elements of queue into stack
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    // push all the elements of stack into ans queue
    while(!s.empty()){
        ans.push(s.top());
        s.pop();
    }
    return ans;
}

//Approach 2-> using Recursion
// T.C-> O(N)
// S.C-> O(1)

void reverse(queue<int>&q){
    //Base case
    if(q.empty()){
        return ;
    }
    // storing the fornt element 
    int temp=q.front();
    // poping
    q.pop();
    // calling the recursive fuction
    reverse(q);
    // at the end pushing the temp into queue
    q.push(temp);
}
queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}