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
    TreeNode* fun(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder,
                  vector<int>& inorder, unordered_map<int, int>& inMap) {
        if (preStart > preEnd or inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int pos = inMap[preorder[preStart]];
        int len = pos - inStart;
        root->left = fun(preStart + 1, preStart + len, inStart, pos - 1, preorder, inorder, inMap);
        root->right = fun(preStart + len + 1, preEnd, pos + 1, preEnd, preorder, inorder, inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }
        return fun(0, n - 1, 0, n - 1, preorder, inorder, inMap);
    }
};
