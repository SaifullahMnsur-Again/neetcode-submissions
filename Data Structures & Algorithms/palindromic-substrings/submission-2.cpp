class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> isPal(s.size(), vector<bool>(s.size(), false));

        for(int i = 0; i < s.size(); i++) 
            isPal[i][i] = true;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == s[i + 1])
                isPal[i][i+1] = true;
        }
        for(int len = 3; len <= s.size(); len++) {
            for(int i = 0; i + len <= s.size(); i++) {
                int j = i + len - 1;
                if(s[i] == s[j] and isPal[i + 1][j - 1])
                    isPal[i][j] = true;
            }
        }

        int ans = 0;
        for(auto i : isPal) {
            for(auto j : i) {
                ans += j;
                // cerr << j << " ";
            }
            // cerr << endl;
        }

        return ans;
    }
};
