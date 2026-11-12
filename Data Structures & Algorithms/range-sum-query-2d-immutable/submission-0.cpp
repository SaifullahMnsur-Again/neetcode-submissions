class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        sum.resize(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int top = i > 0 ? sum[i-1][j] : 0;
                int left = j > 0 ? sum[i][j-1] : 0;
                int topLeft = i > 0 and j > 0 ? sum[i-1][j-1] : 0;
                int curr = matrix[i][j];
                int newSum = top + left - topLeft + curr;
                sum[i][j] = newSum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int curr = sum[row2][col2];
        int topLeft = row1 > 0 and col1 > 0 ? sum[row1 - 1][col1 - 1] : 0;
        int top = row1 > 0 ? sum[row1 - 1][col2] : 0;
        int left = col1 > 0 ? sum[row2][col1 - 1] : 0;

        return curr - top - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */