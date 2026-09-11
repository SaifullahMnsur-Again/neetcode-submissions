class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int minLen = INT_MAX;
        for(auto i : strs)
            minLen = min(minLen, (int)i.size());

        for(int len = 1; len <= minLen; len++) {
            bool done = true;
            for(int i = 0; i < strs.size(); i++) {
                if(strs[i][len - 1] != strs.back()[len - 1]) {
                    return strs[0].substr(0, len - 1);
                }
            }
        }
        if(strs[0].substr(0, minLen) == strs.back().substr(0, minLen))
            return strs[0].substr(0, minLen);
        return "";
    }
};