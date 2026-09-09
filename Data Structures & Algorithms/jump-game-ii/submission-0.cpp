class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(nums.size(), INT_MAX);
        steps[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j <= nums[i]; j++) {
                if(i + j >= n)
                    break;
                steps[i + j] = min(steps[i + j], steps[i] + 1);
            }
        }

        return steps[n - 1];
    }
};
