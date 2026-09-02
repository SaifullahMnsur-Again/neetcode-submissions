class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) { 
        int n = a.size();
        int m = b.size();

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int start = max(a[i][0], b[j][0]);
                int end = min(a[i][1], b[j][1]);
                if(start <= end) {
                    ans.push_back({start, end});
                }
            }
        }

        return ans;
    }
};