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
    bool fun(TreeNode* root, int Maxi, int Mini) {
        if (!root) return true;

        if (root->val >= Maxi or root->val <= Mini) return false;
        bool left = fun(root->left, root->val, Mini);
        bool right = fun(root->right, Maxi, root->val);

        return left && right;
    }
    bool isValidBST(TreeNode* root) { return fun(root, INT_MAX, INT_MIN); }
};
