class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(int i = 0; i < strs.size(); i++) {
            string cnt(26, 0);
            for(auto j : strs[i]) {
                cnt[j - 'a']++;
            }
            ump[cnt].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto i : ump)
            ans.push_back(i.second);

        return ans;
    }
};
