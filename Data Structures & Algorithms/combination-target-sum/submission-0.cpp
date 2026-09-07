class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int target, vector<int> &curr, int i) {
        if(target < 0)
            return;
        
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        
        if(i >= nums.size())
            return;
        
        curr.push_back(nums[i]);
        dfs(nums, target - nums[i], curr, i);
        curr.pop_back();
        dfs(nums, target, curr, i + 1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        // for(int i = 0; i < nums.size(); i++) {
            dfs(nums, target, curr, 0);
        // }

        return ans;
    }
};
