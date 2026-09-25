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
    int ans = INT_MIN;
    int fun(TreeNode* root) {
        if (!root) return 0;

        int left = fun(root->left);
        int right = fun(root->right);
        int leftMax = max(0, left);
        int rightMax = max(0, right);
        ans = max(ans, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
    }
};
