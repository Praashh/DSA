// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

// Approach Check for Left Subtree and Check for Right Subtree and if height of tree is <=1 then balanced

// T.C-> O(N^2) and S.C-> O(N)

class Solution
{
public:
    int height(struct TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int left_height = height(node->left);
        int right_height = height(node->right);
        int Final_height = max(left_height, right_height) + 1;
        return Final_height;
    }

    bool isBalanced(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return true;
        }
        bool left = isBalanced(root->left);

        bool right = isBalanced(root->right);
        // If i don't Consider abs value then it will not work
        bool diffrence = abs(height(root->left) - height(root->right)) <= 1;

        if (left && right && diffrence)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Approach 2-> Using pair of Balanced(bool datatype) and the height
// T.C->O(N) and S.C->O(N)

class Solution
{
public:
    int height(struct TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int left_height = height(node->left);
        int right_height = height(node->right);
        int Final_height = max(left_height, right_height) + 1;
        return Final_height;
    }
    pair<bool, int> help(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        pair<bool, int> left = help(root->left);

        pair<bool, int> right = help(root->right);

        bool op1 = left.first;

        bool op2 = right.first;

        bool op3 = abs(left.second - right.second) <= 1;
        pair<bool, int> ans;

        if (op1 && op2 && op3)
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    bool isBalanced(TreeNode *root)
    {

        return help(root).first;
    }
};