class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            cout << mid << " ";
            if (matrix[mid][0] <= target and matrix[mid][m - 1] >= target) {
                cout << mid;
                int left = 0, right = m - 1;
                while (left <= right) {
                    int mid1 = (left + right) / 2;
                    if (matrix[mid][mid1] == target)
                        return true;
                    else if (matrix[mid][mid1] > target) {
                        right = mid1 - 1;
                    } else
                        left = mid1 + 1;
                }
                return false;
            } else if (matrix[mid][m - 1] < target) {
                i = mid + 1;
            } else
                j = mid - 1;
        }
        return false;
    }
};
