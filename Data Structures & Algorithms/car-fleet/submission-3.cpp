class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int, int>> vp;

        for(int i = 0; i < p.size(); i++) {
            vp.push_back({p[i], s[i]});
        }
        sort(vp.rbegin(), vp.rend());

        int fleet = 0;
        double maxx = 0.0L;
        for(auto i : vp) {
            double need = (double)(target - i.first) / i.second;
            if(maxx < need) {
                fleet++;
            }
            maxx = max(maxx, need);
        }
        
        return fleet;
    }
};
