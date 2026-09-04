class Solution {
    vector<vector<int>> ans;
    
    void getSubset(vector<int> &nums, vector<int> &curr, int i) {
        if(i >= nums.size())
            return;
        curr.push_back(nums[i]);
        ans.push_back(curr);
        
        getSubset(nums, curr, i + 1);
        curr.pop_back();
        getSubset(nums, curr, i + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        ans.push_back(curr);
        getSubset(nums, curr, 0);

        return ans;
    }
};
