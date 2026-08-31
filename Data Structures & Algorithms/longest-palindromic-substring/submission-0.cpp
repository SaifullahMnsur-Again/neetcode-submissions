class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        for(int i = 0; i <= n; i++)
            dp[i][i] = true;
        
        int st = 0, ln = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                dp[i-1][i] = true;
                st = i - 1;
                ln = 2;
            }
        }


        for(int i = 3; i <= n; i++) {
            for(int j = 0; j <= n - i; j++) {
                int k = j + i - 1;

                if(s[j] == s[k] and dp[j + 1][k - 1]) {
                    dp[j][k] = true;
                    st = j;
                    ln = i;
                }
            }
        }

        return s.substr(st, ln);
    }
};
