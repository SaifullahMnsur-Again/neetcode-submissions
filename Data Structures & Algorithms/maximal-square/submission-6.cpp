class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 or j == 0)
                        dp[i + 1][j + 1] = 1;
                    else
                        dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                }
                // cerr << dp[i + 1][j + 1] << " ";
                maxx = max(maxx, dp[i + 1][j + 1]);
            }
            // cerr << endl;
        }

        return maxx * maxx;
    }
};