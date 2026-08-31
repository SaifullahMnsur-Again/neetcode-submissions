class Solution {
    bool valid(string s) {
        int n = stoi(s);
        if(s.size() > 1 and n < 10)
            return false;
        if(n == 0)
            return false;
        if(n > 26)
            return false;
        return true;
    }
public:
    int numDecodings(string s) {

        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = valid(s.substr(0, 1));
        for(int i = 2; i <= s.size(); i++) {
            dp[i] = dp[i - 1] * valid(s.substr(i - 1, 1)) + dp[i - 2] * valid(s.substr(i - 2, 2));
        }

        return dp.back();
    }
};
