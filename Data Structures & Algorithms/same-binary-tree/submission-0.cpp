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
    void isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return;
        }

        if (p && !q) {
            ans = false;
            return;
        }

        else if (q && !p) {
            ans = false;
            return;
        }
        if (p->val != q->val) {
            ans = false;
            return;
        }

        if(ans)
        {
        isSame(p->left,q->left);
        isSame(p->right, q->right);
        }

        return ;
    }

        bool isSameTree(TreeNode * p, TreeNode * q) {
            isSame(p,q);
            return ans;
        }
    

    };
