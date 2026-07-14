class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for(auto &i : s)
            cnt[i - 'a']++;
        for(auto &i : t)
            cnt[i - 'a']--;
        for(auto i : cnt)
            if(i != 0)
                return false;
        return true;
    }
};
