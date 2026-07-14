class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0)
                break;

            int need = -nums[i];
            int l = i + 1, r = n - 1;
            while(l < r) {
                if(nums[l] + nums[r] < need)
                    l++;
                else if(nums[l] + nums[r] > need)
                    r--;
                else {
                    while(l + 1 < r && nums[l] == nums[l + 1])
                        l++;
                    while(l < r - 1 && nums[r] == nums[r - 1])
                        r--;
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                }
            }

            while(i < n - 1 && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};
