class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int left = nums.size();
        for(int i = 0; left > 0; i++) {
            int curr = i;
            int t1, t2 = nums[curr];
            do {
                int nw = (curr + k) % nums.size();
                // cerr << curr << " <- " << nw << endl;
                t1 = nums[nw];
                nums[nw] = t2;
                t2 = t1;
                curr = nw;
                left--;
            } while (curr != i);
        }
        return;
    }
};