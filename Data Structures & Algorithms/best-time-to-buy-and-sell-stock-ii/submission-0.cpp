class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0;
        int hold = -prices[0];
        for(auto price : prices) {
            int prev = sold;
            sold = max(sold, hold + price);
            hold = max(hold, prev - price);
        }

        return sold;
    }
};