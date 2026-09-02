class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        sort(customers.begin(), customers.end());

        long long waited = 0;
        long long excess = 0;
        long long nowAt = 0;
        for(int i = 0; i < customers.size(); i++) {
            if(nowAt > customers[i][0]) {
                excess += nowAt - customers[i][0];
            } else {
                nowAt = customers[i][0];
            }

            nowAt += customers[i][1];
            waited += customers[i][1];
            
            // cerr << nowAt << " " << waited << " " << excess << endl;
        }

        return (double)(waited + excess) / customers.size();
    }
};