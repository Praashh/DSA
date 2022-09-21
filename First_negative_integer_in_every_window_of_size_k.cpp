// brute force 
// using deque T.C->o(N) and S.C->o(k)

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    deque<long long int>dq;
    vector<long long> ans;
    // process first window of k size
    for(int i=0;i<K;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    // store ans of first k size window 
    if(dq.size()==0){
        ans.push_back(0);
    }
    else{
        ans.push_back(A[dq.front()]);
    }
    // process for remaining window
    for(int i=K;i<N;i++){
        // Removal
        if( !dq.empty() && i-dq.front()>=K){
            dq.pop_front();
        }
        // addition
        if(A[i]<0){
            dq.push_back(i);
        }
        // store the ans
    if(dq.size()==0){
        ans.push_back(0);
    }
    else{
        ans.push_back(A[dq.front()]);
    }
    }
    return ans;
}               

// Using Sliding Windnow 
// T.C->o(N) and S.C->o(k)



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    queue<long long>q;
    vector<long long>ans;
    long long int i=0,j=0;
    while(j<N){
        //step 1st if we found any negetuve number then push it in queue
        if(A[j]<0){
            q.push(A[j]);
        }
        // step 2nd if this condition is true the increment j
        if(j-i+1<K){
            j++;
        }
        // step 3rd if this condition is true then calculate the answer  
        else if(j-i+1==K){
            // step 4th calculating the answer
            if(q.size()==0){
                ans.push_back(0);
            }
            else{
                // if A[i]==q.front() then we pop element from queue otherwise there are no need to poping the element 
                if(A[i]==q.front()){
                 ans.push_back(q.front());
                 q.pop();
                }
                else{
                 ans.push_back(q.front());
                }
            }
            i++;
            j++;
        }
    }
        
        return ans;                                         
 }