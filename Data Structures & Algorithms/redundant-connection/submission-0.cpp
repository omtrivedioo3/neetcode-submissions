class DSU {
    vector<int> parent, rank;

   public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        // Path compression
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // Union by rank
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
                rank[root_j]++;

            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            return true;  // Successfully added edge
        }
        return false;  // Cycle detected
    }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // Initialize Union-Find arrays

        DSU ds(n+1);
        // Process each edge in the exact order they appear
        for (auto& edge : edges) {
            // If doUnion returns false, it means connecting these two nodes creates a cycle
            if (!ds.unite(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};
