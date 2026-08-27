class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 2, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= cost.size(); i++) {
            if(i > 1)
                dp[i] = min(dp[i], dp[i - 2] + cost[i - 1]);
            if(i < cost.size())
                dp[i] = min(dp[i], dp[i - 1] + cost[i - 1]);
        }
        dp.back() = min(dp[cost.size()], dp[cost.size() - 1]);

        return dp.back();
    }
};
