class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size(), cols = matrix[0].size();
        int l = 0, r = rows * cols - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            int val = matrix[mid/cols][mid%cols];
            cout << val << endl;

            if(val == target) {
                return true;
            } 

            if(val < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};
