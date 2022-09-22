// Company Tags

// Adobe Amazon Cisco FactSet Flipkart Microsoft


// QUESTION -> Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

// Example 1:

// Input :
//         1
//       /   \
//      3     2

// Output: 3 2 1
// Explanation:
// Traversing level 1 : 3 2
// Traversing level 0 : 1


// T.C-> O(N) and S.C->O(N)

vector<int> reverseLevelOrder(Node *root)
{
    
    vector<int>ans;
    stack<Node*>s;
    queue<Node*>q;
    
    q.push(root);
    
    while(!q.empty()){
       Node* curr=q.front();
       q.pop();
       s.push(curr); 
       
        if(curr ->right) {
         q.push(curr ->right);
        }
        if(curr ->left) {
                q.push(curr ->left);
         }

       
    }
    while(!s.empty()){
        ans.push_back(s.top()->data);
        s.pop();
    }
    return ans;
}