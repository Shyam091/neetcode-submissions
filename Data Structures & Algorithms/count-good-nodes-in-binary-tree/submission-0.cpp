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
    int ans = 0;
    void good(TreeNode* root, int val )
    {
        if(!root)
        {
            return ;
        }

        if(root->val >= val)
        {
            ans++;
        }

        good(root->left, max(root->val,val));
        good(root->right, max(root->val,val));



    }
    int goodNodes(TreeNode* root) {
        good(root, INT_MIN);
        return ans;
    }
};
