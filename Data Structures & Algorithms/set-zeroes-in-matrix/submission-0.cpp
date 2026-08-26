class Solution {
public:
    void setZeroes(vector<vector<int>>& mat, int i = 0, int j = 0) {
        int n = mat[0].size(); 
        int m = mat.size();

        if(j == n)
            j = 0, i++;

        while(i < m and j < n and mat[i][j] != 0) {
            j++;
            if(j == n)
                j = 0, i++;
        }

        if(i < m and j < n and mat[i][j] == 0) {
            setZeroes(mat, i, j + 1);
            for(int ii = 0; ii < m; ii++)
                mat[ii][j] = 0;
            for(int jj = 0; jj < n; jj++)
                mat[i][jj] = 0;
        }
    }
};
