class Solution {
   public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();
        int i = 0, j = n - 1;
        while (i < j) {
            int val = num[i] + num[j];
            if (val == target)
                return {i+1, j+1};
            else if (val > target) {
                j--;
            } else
                i++;
        }
        return {-1, -1};
    }
};
