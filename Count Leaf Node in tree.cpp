
// T.C-> O(N)
// S.C-> O(N) 
void inorder(Node*root,int&count){
    if(root==NULL){
        return ;
    }
     inorder(root->left,count);
      if(root->left==NULL && root->right==NULL){
         count++;
     }
    inorder(root->right,count);
}
int countLeaves(Node* root)
{
        int count=0;
      inorder(root,count);
    return count;
}