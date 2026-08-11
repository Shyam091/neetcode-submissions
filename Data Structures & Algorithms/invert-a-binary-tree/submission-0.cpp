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
    TreeNode* revert(TreeNode* root)
    {
        if(!root)
        {
            return root;
        }
        TreeNode* leftTemp = root->left;
        root->left = revert(root->right);
        root->right =  revert(leftTemp);

        return root ;

    }
    TreeNode* invertTree(TreeNode* root) {
        revert(root);
        return root;
    }
};
