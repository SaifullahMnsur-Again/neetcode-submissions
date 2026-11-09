class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0;
        int cnt = 0;
        int ans = INT_MAX;
        for(int l = 0, r = 0; r < blocks.size(); r++) {
            cnt += (blocks[r] == 'W');

            if(r - l + 1 >= k) {
                ans = min(ans, cnt);
                cnt -= (blocks[l] == 'W');
                l++;
            }
        }

        return ans;
    }
};