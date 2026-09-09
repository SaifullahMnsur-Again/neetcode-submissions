class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> ans;
        for(char c : s) {
            if(!ans.empty() and c == ans.back().first) {
                ans.back().second++;
                while(!ans.empty() and ans.back().second >= k) {
                    ans.back().second -= k;
                    if(ans.back().second == 0) {
                        ans.pop_back();
                    } else if(ans.size() > 1 and ans[ans.size() - 1].first == ans[ans.size() - 2].first) {
                        int t = ans.back().second;
                        ans.pop_back();
                        ans.back().second += t;
                    }
                }
            } else {
                ans.push_back({c, 1});
            }
        }
        string sans;
        for(auto i : ans) {
            for(int j = 0; j < i.second; j++) {
                sans += i.first;
            }
        }

        return sans;
    }
};