class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] < '0' || s[l] > '9' && s[l] < 'A' || s[l] > 'Z' && s[l] < 'a' || s[l] > 'z')
                l++;
            else if(s[r] < '0' || s[r] > '9' && s[r] < 'A' || s[r] > 'Z' && s[r] < 'a' || s[r] > 'z')
                r--;
            else if(tolower(s[l]) == tolower(s[r]))
                l++, r--;
            else
                return false;
        }
        return true;
    }
};
