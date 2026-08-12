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
    
    int ans=INT_MIN;
    void dfs(TreeNode* root, int count)
    {
        if(!root)
        {
            ans = max(ans , count);
        return ;
        }

        dfs(root->left, count+1);
        dfs(root->right, count+1);
    }
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        dfs(root, 0);
        return ans;
    }
};
