class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            dp[i] = nums[i-1];
            if(i > 1)
                dp[i] = max(dp[i] + dp[i-2], dp[i-1]);
        }
        

        return max(dp[n-1], dp[n]);
    }
};
