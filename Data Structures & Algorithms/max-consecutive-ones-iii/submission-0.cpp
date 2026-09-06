class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int rem = k;
        int ans = 0;
        while(l < nums.size()) {
            if(r < nums.size()) {
                if(nums[r] == 0) {
                    while(rem < 1) {
                        if(nums[l] == 0)
                            rem++;
                        l++;
                        // cerr << "l++ ";
                    }
                    rem--;
                }
                r++;
            } else {
                l++;
            }
            // cerr << l << " -> " << r << " rem: " << rem << endl;
            ans = max(ans, r - l);
            // cerr << ans << " ";
            // l++;
        }

        return ans;
    }
};