// QUESTION-> Given a Binary Search Tree and a node value X, find if the node with value X is present in the BST or not.


// Example 1:

// Input:         2
//                 \
//                  81 
//                /    \ 
//              42      87 
//               \       \ 
//                66      90 
//               / 
//             45
// X = 87
// Output: 1
// Explanation: As 87 is present in the
// given nodes , so the output will be
// 1.

// Approach -> we can solve this problem using Recursion

// T.C-> O(N) , S.C-> O(N)

// Function to search a node in BST.
bool search(Node* root, int x) {
    if(root==NULL){
        return 0;
    }
    if(root->data==x){
        return 1;
    }
    //recursive call for left
    if(root->data>x){
      return search(root->left,x);
    }
    else{
     return search(root->right,x);
    }
    
   // return 0;
}