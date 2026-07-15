class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        vector<int> result(tmp.size());
        stack<pair<int, int>> stc;

        for(int i = tmp.size()-1; i >= 0; i--) {
            while(!stc.empty() && tmp[i] >= stc.top().second)
                stc.pop();
            
            if(stc.empty())
                result[i] = 0;
            else
                result[i] = stc.top().first - i;
            
            stc.push({i, tmp[i]});
        }

        return result;
    }
};
