class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = 1LL * x;
        long long add = 1LL * (n - 1);
        int i = 0, j = 0;
        while(i < 63) {
            if((ans&(1LL << i)) == 0) {
                ans |= ((add & 1LL) << i);
                add >>= 1;
            }
                i++;
        }

        return ans;
    }
};