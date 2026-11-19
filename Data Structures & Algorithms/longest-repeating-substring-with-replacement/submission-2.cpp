class Solution {
    int counter(vector<int> &freq) {
        return accumulate(freq.begin(), freq.end(), 0) - *max_element(freq.begin(), freq.end());
    }
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0, r = 0;
        int ans = 0;
        while(r < s.size()) {
            freq[s[r] - 'A']++;
            while(counter(freq) > k and l <= r) {
                freq[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
