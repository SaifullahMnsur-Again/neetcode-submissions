class Solution {
public:
    int numDecodings(string s) {
        map<string, bool> mp;
        for(char c = 'A'; c <= 'Z'; c++) {
            string num = to_string((int)c - 'A' + 1);
            mp[num] = true;
        }

        vector<int> dp(s.size() + 1, 0);
        // dp[0] = mp[s.substr(0, 1)];
        dp[0] = 1;
        dp[1] = mp[s.substr(0, 1)];
        for(int i = 2; i <= s.size(); i++) {
            dp[i] = dp[i - 1] * mp[s.substr(i - 1, 1)] + dp[i - 2] * mp[s.substr(i - 2, 2)];
        }

        return dp.back();
    }
};
