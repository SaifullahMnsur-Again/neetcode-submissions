class Solution {
    double getTime(int target, int position, int speed) {
        return (double)(target - position) / speed;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;
        for(int i = 0; i < position.size(); i++) {
            ps.push_back({position[i], speed[i]});
        }
        sort(ps.begin(), ps.end());
        double minTime = getTime(target, ps.back().first, ps.back().second);
        int ans = 1;
        for(int i = position.size() - 2; i >= 0; i--) {
            double currTime = getTime(target, ps[i].first, ps[i].second);
            if(currTime - minTime> 1e-6) {
                ans++;
                minTime = currTime;
            }
        }

        return ans;
    }
};
