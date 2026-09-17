class Solution {
    int ans = 0;
    void combs(vector<int> &nums, int i, int curr) {
        if(i >= nums.size())
            return;
        combs(nums, i + 1, curr^nums[i]);
        ans +=  curr^nums[i];
        combs(nums, i + 1, curr);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        combs(nums, 0, 0);
        return ans;
    }
};