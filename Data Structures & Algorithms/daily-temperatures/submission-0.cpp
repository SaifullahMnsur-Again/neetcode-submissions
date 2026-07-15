class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        vector<int> result;
        vector<int> date(101, -1);
        for(int i = tmp.size()-1; i >= 0; i--) {
            int j = tmp[i] + 1;

            int minn = INT_MAX;
            while(j <= 100) {
                if(date[j] > -1) {
                    minn = min(minn, date[j] - i);
                }
                j++;
            }
            if(minn == INT_MAX)
                minn = 0;

            result.push_back(minn);

            date[tmp[i]] = i;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
