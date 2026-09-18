class Solution {
    vector<string> mp = {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> ans;
    
    void getComb(string digits, int i, string curr) {
        if(i >= digits.size()) {
            if(!curr.empty())
                ans.push_back(curr);
            return;
        }
        int dig = digits[i] - '0';
        for(int j = 0; j < mp[dig].size(); j++) {
            getComb(digits, i + 1, curr + mp[dig][j]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        getComb(digits, 0, "");
        return ans;
    }
};
