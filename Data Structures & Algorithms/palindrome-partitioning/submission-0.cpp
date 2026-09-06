class Solution {
    vector<vector<string>> ans;
    vector<pair<int, int>> pos;

    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i<= j; i++, j--) {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }

    void addAns(string &s) {
        vector<string> temp;
        for(auto i : pos) {
            temp.push_back(s.substr(i.first, i.second));
        }
        ans.push_back(temp);
    }

    void dfs(string &s, int p) {
        if(p >= s.size()) {
            addAns(s);
        }
        for(int len = 1; p + len <= s.size() ; len++) {
            if(isPalindrome(s.substr(p, len))) {
                pos.push_back({p, len});
                dfs(s, p + len);
                pos.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        
        return ans;
    }
};
