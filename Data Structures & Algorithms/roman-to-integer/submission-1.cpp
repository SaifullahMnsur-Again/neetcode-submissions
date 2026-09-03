class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == 'I') {
                if((i < s.size() - 1) and (s[i + 1] == 'V' or s[i + 1] == 'X')) {
                    num--;
                } else {
                    num++;
                }
            } else if (s[i] == 'X') {
                if((i < s.size() - 1) and (s[i + 1] == 'L' or s[i + 1] == 'C')) {
                    num -= 10;
                } else {
                    num += 10;
                }
            } else if(s[i] == 'C') {
                if((i < s.size() - 1) and (s[i + 1] == 'D' or s[i + 1] == 'M')) {
                    num -= 100;
                } else {
                    num += 100;
                }
            } else if(s[i] == 'V') {
                num += 5;
            } else if(s[i] == 'L') {
                num += 50;
            } else if(s[i] == 'D') {
                num += 500;
            } else {
                num += 1000;
            }
            // cerr << num << " ";
        }

        return num;
    }
};