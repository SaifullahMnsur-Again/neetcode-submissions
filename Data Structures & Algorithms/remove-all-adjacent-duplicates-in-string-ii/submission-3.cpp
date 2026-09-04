class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            ans.push_back(s[i]);
            if(ans.size() >= k) {
                bool same = true;
                for(int j = 1; j < k; j++)
                    if(ans.back() != ans[ans.size() - 1 - j])
                        same = false;
                if(same)
                    for(int j = 0; j < k; j++)
                        ans.pop_back();
            }
        }

        return ans;
    }
};