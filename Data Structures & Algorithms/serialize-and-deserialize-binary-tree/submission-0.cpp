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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st;
        if (!root) return st;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                st += to_string(node->val);
                st.push_back(',');
            } else {
                st.push_back('#');
                st.push_back(',');
            }
            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        st.pop_back();
        cout << st;
        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return nullptr;
        stringstream ss(data);
        string s;
        getline(ss, s, ',');
        queue<TreeNode*> q;
        int val = stoi(s);
        TreeNode* root = new TreeNode(val);
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(ss, s, ',');
            if (s != "#") {
                node->left = new TreeNode(stoi(s));
                q.push(node->left);
            }
            getline(ss, s, ',');
            if (s != "#") {
                node->right = new TreeNode(stoi(s));
                q.push(node->right);
            }
        }
        return root;
    }
};
