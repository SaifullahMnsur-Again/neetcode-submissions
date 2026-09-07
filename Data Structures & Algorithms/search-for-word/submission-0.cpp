class Solution {
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>> &vis, int i, int j, int k) {
        if(i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or k >= word.size() or vis[i][j])
            return false;

        if(board[i][j] != word[k])
            return false;

        if(k == word.size() - 1)
            return true;
        
        vis[i][j] = true;
        for(auto d : dirs) {
            if(dfs(board, word, vis, i + d[0], j + d[1], k + 1))
                return true;
        }
        
        vis[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(board, word, vis, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
