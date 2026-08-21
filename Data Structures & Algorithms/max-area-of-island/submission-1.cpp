class Solution {

    bool isValid(int i, int ii, int j, int jj, int n, int m) {
        if(i + ii < 0 || i + ii >= n)
            return false;
        if(j + jj < 0 || j + jj >= m)
            return false;
        return true;
    }
    int DFS(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &dirs) {
        if(grid[i][j] == 0 || vis[i][j])
            return false;

        int ret = 1;
        vis[i][j] = true;

        for(auto &[r, c] : dirs) {
            if(isValid(i, r, j, c, grid.size(), grid[0].size()) && !vis[i + r][j + c] && grid[i + r][j + c] == 1)
            ret += DFS(i + r, j + c, grid, vis, dirs);
        }

        return ret;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

        int cnt = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                cnt = max(cnt, DFS(i, j, grid, vis, dirs));
            }
        }

        return cnt;
    }
};
