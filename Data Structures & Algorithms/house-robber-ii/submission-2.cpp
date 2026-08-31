class Solution {

    int rob(vector<int> &nums, int l, int r) {
        vector<int> dp(r + 1);

        for(int i = l; i <= r; i++) {
            dp[i] = nums[i-1];
            if(i > 1)
                dp[i] = max(dp[i] + dp[i-2], dp[i-1]);
        }
        

        return max(dp[r-1], dp[r]);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        
        return max(rob(nums, 1, n-1), rob(nums, 2, n));
    }
};
