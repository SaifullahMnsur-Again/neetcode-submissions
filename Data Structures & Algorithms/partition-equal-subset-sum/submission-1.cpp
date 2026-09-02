class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum%2)
            return false;
        
        int target = sum / 2;
        
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(auto num : nums) {
            for(int i = target; i >= num; i--) {
                if(dp[i - num])
                    dp[i] = true;
            }
        }
        return dp[target];
    }
};
