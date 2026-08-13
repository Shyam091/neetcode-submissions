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
    bool ans = true;
    int checkBalanced(TreeNode*  root)
    {
        if(!root)
        {
            return 0;
        }

        int left =0;
        int right = 0;
        if(!ans)
        {
            return 0;
        }
        left+=checkBalanced(root->left);
        right+=checkBalanced(root->right);
        if(abs(left - right) >=2)
        {
            ans = false;
            return 0;
        }

        return max(left,right)+1;

    }
    bool isBalanced(TreeNode* root) {
        checkBalanced(root);
        return ans;
    }
};
