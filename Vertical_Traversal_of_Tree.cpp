// Vertical Traversal of Binary Tree
// T.C->O(N) and S.C->O(N)

void leftView(Node*root,vector<int>&ans,int lvl){
     // base case
     if(root==NULL){
         return ;
     }
     if(lvl==ans.size()){
         ans.push_back(root->data);
         
     }
     leftView(root->right,ans,lvl+1);
     leftView(root->left,ans,lvl+1);
   
   
    
     
}
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
         int lvl=0;
         vector<int>ans;
       leftView(root,ans,lvl);
   return ans;
    }
};