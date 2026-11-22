class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int i = curr[0], j = curr[1];

            for(auto &[di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;
                if(ni >= 0 and ni < m and nj >= 0 and nj < n and grid[ni][nj] == INT_MAX) {
                    grid[ni][nj] = grid[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
};
