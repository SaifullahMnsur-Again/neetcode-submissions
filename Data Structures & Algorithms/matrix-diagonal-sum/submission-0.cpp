class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = 0; i < mat.size(); i++) {
            sum += mat[i][i];
            if(mat.size()%2 == 1 and mat.size() / 2 == i){

            } else 
                sum += mat[i][mat.size() - 1 - i];
        }

        return sum;
    }
};