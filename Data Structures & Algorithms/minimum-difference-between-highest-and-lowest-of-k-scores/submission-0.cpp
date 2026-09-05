class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        multiset<int> mst;
        for(int i = 1; i < k; i++)
            mst.insert(nums[i - 1]);
        int ans = INT_MAX;
        for(int i = k - 1; i < nums.size(); i++) {
            // cerr << i << " ";
            mst.insert(nums[i]);
            // cerr << *mst.rbegin() << " " << *mst.begin() << " -> ";
            ans =  min(ans, *mst.rbegin() - *mst.begin());
            mst.erase(mst.lower_bound(nums[i - k + 1]));
            // cerr << mst.size() << endl;
        }

        return ans;
    }
};