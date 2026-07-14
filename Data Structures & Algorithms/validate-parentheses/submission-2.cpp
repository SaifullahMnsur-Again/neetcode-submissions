class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        for(char &i : s) {
            if(i == ']' || i == '}' || i == ')') {
                if(!stc.empty() && abs(i - stc.top()) <= 2)
                    stc.pop();
                else
                    return false;
            } else {
                stc.push(i);
            }
        }

        if(stc.empty())
            return true;
        return false;
    }
};
