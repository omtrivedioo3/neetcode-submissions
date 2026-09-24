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
    void fun(TreeNode* root, int maxValue) {
        if (!root) return;

        if (root->val >= maxValue) {
            ans++;
        }
        fun(root->left, max(maxValue, root->val));
        fun(root->right, max(maxValue, root->val));
        return;
    }
    int goodNodes(TreeNode* root) {
        fun(root, INT_MIN);
        return ans;
    }
};
