class Solution {
    vector<vector<int>> dirs = {{1, 0}, {0, 1}};
    vector<vector<int>> v;
    void calc(vector<vector<int>> &grid, int i, int j, int n, int m, int sum) {
        if(i < 0 or i >= n or j < 0 or j >= m)
            return;
        if(sum + grid[i][j] >= v[i][j])
            return;
        
        v[i][j] = sum + grid[i][j];
        if(i == n - 1 and j == m - 1)
            return;
        
        for(auto d : dirs) {
            int di = i + d[0];
            int dj = j + d[1];
            calc(grid, di, dj, n, m, v[i][j]);
        }
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        v.assign(n, vector<int>(m, INT_MAX));
        calc(grid, 0, 0, n, m, 0);

        return v.back().back();
    }
};