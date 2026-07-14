class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int ln = 20000;
        vector<pair<int, int>> freq(ln + 1);
        for(int i : nums) {
            freq[(i + ln) % ln].first++;
            freq[(i + ln) % ln].second = i;
        }
        sort(freq.rbegin(), freq.rend());
        vector<int> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(freq[i].second);
        return ans;
    }
};
