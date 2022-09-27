// QUESTION-> Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

// Example 1:

// Input: root = [1,3,2,5,3,null,9]
// Output: [1,3,9]

// APPROACH ->using BFS(Level Order Traversal) We can Easily Solve this Problem
// T.C->O(N) and S.C->O(N)

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans = {};
        queue<TreeNode *> q;
        int maxi = INT_MIN;
        if (root == NULL)
        {
            return ans;
        }

        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)// it means Level Completed
            { 
                ans.push_back(maxi);
                maxi = INT_MIN; // Why INT_MIN because if tree [0,-1] in case maxi will be 0 so this condition is important
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                maxi = max(temp->val, maxi);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};