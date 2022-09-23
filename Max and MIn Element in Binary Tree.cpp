// QUESTION -> Given a Binary Tree, find maximum and minimum elements in it.
// Example :

// Input: 
//            6
//         / \
//        5   8
//       /
//      2
// Output: 8 2

// T.C-> O(N) and S.C-> O(N)

class Solution
{
public:
    int findMax(Node *root)
    {
       int maxi=INT_MIN;
       int left_maxi,right_maxi;
       // base case
       if(root==NULL){
           return maxi;
       }
       if(root->data>maxi){
           maxi=root->data;
       }
       // recursive call for left node
       left_maxi=findMax(root->left);
       if(left_maxi>maxi){
           maxi=left_maxi;
       }
       // recursive call for right node
       right_maxi=findMax(root->right);
       if(right_maxi>maxi){
           maxi=right_maxi;
       }
       return maxi;
    }
    int findMin(Node *root)
    {
        int mini=INT_MAX;
        int left_mini,right_mini;
        // base case
        if(root==NULL){
            return mini;
        }
        if(root->data<mini){
            mini=root->data;
        }
        // recursive call for left node
        left_mini=findMin(root->left);
        if(left_mini<mini){
            mini=left_mini;
        }
        // recursive call for right node
        right_mini=findMin(root->right);
        if(right_mini<mini){
            mini=right_mini;
        }
        return mini;
    }
};