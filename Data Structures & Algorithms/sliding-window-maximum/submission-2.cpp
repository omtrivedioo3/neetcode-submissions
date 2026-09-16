class SegmentTree {
   private:
    vector<int> tree;
    int n;

    // Recursive function to build the tree
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftNode = 2 * node + 1;
            int rightNode = 2 * node + 2;

            // Recursively build the left and right children
            build(arr, leftNode, start, mid);
            build(arr, rightNode, mid + 1, end);

            // Internal node will have the max of both of its children
            tree[node] = max(tree[leftNode], tree[rightNode]);
        }
    }

    // Recursive function to answer range maximum queries
    int query(int node, int start, int end, int l, int r) {
        // 1. Completely outside the given range
        if (r < start || end < l) {
            return INT_MIN;  // Return minimum possible value
        }

        // 2. Completely inside the given range
        if (l <= start && end <= r) {
            return tree[node];
        }

        // 3. Partially inside and partially outside
        int mid = start + (end - start) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;

        int leftQuery = query(leftNode, start, mid, l, r);
        int rightQuery = query(rightNode, mid + 1, end, l, r);

        return max(leftQuery, rightQuery);
    }

    // Recursive function to update a specific index
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            // Leaf node
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftNode = 2 * node + 1;
            int rightNode = 2 * node + 2;

            if (start <= idx && idx <= mid) {
                // If idx is in the left child, recurse on the left child
                update(leftNode, start, mid, idx, val);
            } else {
                // If idx is in the right child, recurse on the right child
                update(rightNode, mid + 1, end, idx, val);
            }

            // Update the current node after updating the children
            tree[node] = max(tree[leftNode], tree[rightNode]);
        }
    }

   public:
    // Constructor
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        // The maximum size of segment tree is 4 * n
        tree.assign(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    // Wrapper for range max query
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }

    // Wrapper for point update
    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }
};
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree st(nums);

        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++) {
            ans.push_back(st.query(i, i + k - 1));
        }
        return ans;
    }
};
