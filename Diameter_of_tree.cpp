

// APPROACH 1-> There are three things in which diameter exits 1st-> in left Subtree , 2nd-> in right Subtree
// 3rd-> in combination of both Subtrees and the Maximum of these three is the Diameter of Tree
// T.C->O(N^2) and S.C->O(N)

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
        int Final_height = max(left = _height, right_height) + 1;
        return Final_height;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int path1 = diameterOfBinaryTree(root->left);
        int path3 = height(root->left);
        int path2 = diameterOfBinaryTree(root->right);

        int path4 = height(root->right);

        int path5 = path3 + path4;
        int ans = max(path1, max(path2, path5));

        return ans;
    }
};

// APPROACH 2-> Time O(N) and Space O(N) Using Pair of Daimeter and Height

int height(struct TreeNode *node)
{
    // base case
    if (node == NULL)
    {
        return 0;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    int Final_height = max(left_height, right_height) + 1;
    return Final_height;
}
pair<int, int> Diameterfast(TreeNode *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = Diameterfast(root->left);
    pair<int, int> right = Diameterfast(root->right);

    // diameter for left subtree
    int op1 = left.first;
    // diameter for right subtree
    int op2 = right.first;

    // combo of bothe subtrees or the height of tree without including root node
    int op3 = left.second + right.second;

    pair<int, int> ans;
    // Maximum Diameter
    ans.first = max(op1, max(op2, op3));
    // Maximum Height
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameterOfBinaryTree(TreeNode *root)
{

    return Diameterfast(root).first;
}