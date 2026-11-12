class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);
        for(auto num : nums)
            freq[num]++;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            while(freq[j] == 0) {
                j++;
            }
            freq[j]--;
            nums[i] = j;
        }
    }
};