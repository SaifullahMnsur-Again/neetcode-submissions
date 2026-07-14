class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int maxx = 0, curr = 0, prev = *st.begin() - 1;
        for(auto i : st) {
            if(prev + 1 == i) {
                curr++;
            } else {
                curr = 1;
            }
            maxx = max(maxx, curr);
            prev = i;
        }

        return maxx;
    }
};
