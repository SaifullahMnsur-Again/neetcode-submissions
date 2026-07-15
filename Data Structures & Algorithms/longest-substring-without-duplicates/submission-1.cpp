class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;

        int freq[130] = {0};
        int maxx = 0;
        while(r < s.length()) {
            while(freq[s[r]] > 0) {
                freq[s[l++]]--;
            }
            
            maxx = max(maxx, r - l + 1);

            freq[s[r++]]++;
        }

        return maxx;
    }
};
