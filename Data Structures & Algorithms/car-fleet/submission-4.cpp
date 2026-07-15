class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int, int>> vp;

        for(int i = 0; i < p.size(); i++) {
            vp.push_back({p[i], s[i]});
        }
        sort(vp.rbegin(), vp.rend());

        stack<double> stc;
        for(auto i : vp) {
            double need = (double)(target - i.first) / i.second;
            if(!stc.empty()) {
                if(stc.top() >= need) {
                    continue;
                }
            }
            stc.push(need);
        }
        
        return stc.size();
    }
};
