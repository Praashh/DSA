// QUESTION-> Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

// Example 1:

// Input: root = [1,null,2,3]
// Output: [1,3,2]

// T.C->O(N) and S.C-> O(N)

class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
};