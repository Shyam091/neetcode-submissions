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
    // we can simply solve it by inorder traversing 
    int val = INT_MIN;
    bool ans = true;
    void bst(TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        
        bst(root->left);
        if(root->val <= val)
        {
            ans = false;
        }
        else{
            val =  root->val;
        }
        bst(root->right);
    }
    bool isValidBST(TreeNode* root) {
        bst(root);
        return ans;
    }
};
