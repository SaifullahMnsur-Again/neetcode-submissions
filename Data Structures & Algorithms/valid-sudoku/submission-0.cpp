class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<int>> rows(n, vector<int>(n, 1));
        vector<vector<int>> cols(n, vector<int>(n, 1));
        vector<vector<int>> segs(n, vector<int>(n, 1));

        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] != '.') {
                    rows[i][board[i][j] - '1']--;
                    cols[j][board[i][j] - '1']--;
                    segs[(i/3)*3 + j/3][board[i][j] - '1']--;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 9; j++) {
                if(rows[i][j] < 0 || cols[i][j] < 0 || segs[i][j] < 0)
                    return false;
            }
        }

        return true;
    }
};
