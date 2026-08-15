class Solution {
    long long getHours(vector<int> &piles, int k) {
        long long sum = 0;
        for(auto i : piles) {
            sum += (i + k - 1) / k;
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        int k = 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            long long hours = getHours(piles, mid);
            if(hours <= h) {
                k = mid;
                r = mid - 1;
                // cout << "Hours: " << k << endl;
            } else {
                l = mid + 1;
            }
        }

        return k;
    }
};
