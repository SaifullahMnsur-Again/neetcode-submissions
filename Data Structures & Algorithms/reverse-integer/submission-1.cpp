class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0) {
            if(x < 0 and INT_MIN / 10 > rev or x >= 0 and INT_MAX / 10 < rev)
                return 0;

            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};
