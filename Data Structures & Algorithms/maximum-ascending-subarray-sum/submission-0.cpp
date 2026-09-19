class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int curr = nums[0];
        int i = 1;

        while(i < nums.size()) {
            if(nums[i - 1] >= nums[i])
                curr = 0;
            curr += nums[i++];
            sum = max(sum, curr);
        }

        return sum;
    }
};