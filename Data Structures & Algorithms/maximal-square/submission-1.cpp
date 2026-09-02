class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ones(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                ones[i][j] = ones[i - 1][j] + ones[i][j - 1] - ones[i - 1][j - 1] + (matrix[i - 1][j - 1] == '1');
                // cerr << ones[i][j] << " ";
            }
            // cerr << endl;
        }

        int maxx = 0;
        for(int sz = 1; sz <= min(n, m); sz++) {
            for(int i = sz; i <= n; i++) {
                for(int j = sz; j <= m; j++) {
                    int curr = ones[i][j] - ones[i - sz][j] - ones[i][j - sz] + ones[i - sz][j - sz];
                    // cerr << curr << endl;
                    if(curr == sz * sz)
                        maxx = max(maxx, curr);
                }
            }
        }

        return maxx;
    }
};