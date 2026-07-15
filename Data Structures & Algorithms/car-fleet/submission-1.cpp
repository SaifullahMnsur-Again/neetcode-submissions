class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int, int>> vp;

        for(int i = 0; i < p.size(); i++) {
            vp.push_back({p[i], s[i]});
        }
        sort(vp.rbegin(), vp.rend());

        set<double> st;
        for(auto i : vp) {
            double need = (double)(target - i.first) / i.second;
            if(!st.empty()) {
                if(*st.rbegin() >= need) {
                    continue;
                }
            }
            cout << target << " - " << i.first << " / " << i.second << " -> " << need << endl;
            st.insert(need);
        }
        for(auto i : st)
            cout << i << " ";
        
        return st.size();
    }
};
