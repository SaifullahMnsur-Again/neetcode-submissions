class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size() - 1;
        int u = 0, d = matrix.size() - 1;

        int i = 0, j = 0;

        int rem = (r + 1) * (d + 1);

        vector<int> ans;
        while(rem > 0) {
            while(rem > 0 and j <= r) {
                ans.push_back(matrix[i][j++]);
                rem--;
            }
            u++;
            j = r; i = u;

            while(rem > 0 and i <= d) {
                ans.push_back(matrix[i++][j]);
                rem--;
            }
            r--;            
            i = d; j = r;

            while(rem > 0 and j >= l) {
                ans.push_back(matrix[i][j--]);
                rem--;
            }
            d--;
            j = l; i = d;

            while(rem > 0 and i >= u) {
                ans.push_back(matrix[i--][j]);
                rem--;
            }
            l++;
            i = u; j = l; 
        }

        return ans;
    }
};
