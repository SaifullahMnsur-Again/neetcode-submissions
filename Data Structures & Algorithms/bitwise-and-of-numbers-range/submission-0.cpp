class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i = 0; i < 31; i++) {
            int base = 1 << i;

            if(left&base and right&base and (right-left) <= base)
                ans |= base;
        }

        return ans;
    }
};