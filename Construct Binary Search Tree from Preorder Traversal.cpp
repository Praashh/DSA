/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Preorder(TreeNode*&root,int x){
        if(root==NULL){
            root=new TreeNode(x);
            return ;
        }
        if(x > root->val){
            Preorder(root->right,x);
        }
        else{
            Preorder(root->left,x);

        }


    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(auto i:preorder){
            Preorder(root,i);
        }
        return root;
    }
};