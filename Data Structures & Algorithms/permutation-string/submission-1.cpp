class Solution {
    bool check(vector<int> &f1, vector<int> &f2) {
        for(int i = 0; i < 26; i++) {
            if(f1[i] != f2[i])
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0), f2(26, 0);
        set<int> mismatch;
        for(auto i : s1) {
            f1[i - 'a']++;
        }
        int l = s1.size() - 1;
        for(int i = 0; i < s2.size(); i++) {
            f2[s2[i] - 'a']++;
            // if(check(f1, f2))
            //     return true;
            if(f1 == f2)
                return true;
            if(i >= l)
                f2[s2[i - l] - 'a']--;
        }
        return false;
    }
};
