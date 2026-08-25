class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j <= n; j++) {
                if((j / (1 << i))&1)
                    ans[j]++;
            }
        }

        return ans;
    }
};
