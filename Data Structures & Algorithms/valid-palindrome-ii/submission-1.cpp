class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r and s[l] == s[r]) {
            l++, r--;
        }
        if(l > r)
            return true;
        
        bool isPal = true;
        for(int i = l + 1, j = r; i <= j; i++, j--) {
            if(s[i] != s[j]) {
                isPal = false;
                break;
            }
        }
        if(isPal)
            return true;

        isPal = true;
        for(int i = l, j = r - 1; i <= j; i++, j--) {
            if(s[i] != s[j]) {
                isPal = false;
                break;
            }
        }

        return isPal;
    }
};