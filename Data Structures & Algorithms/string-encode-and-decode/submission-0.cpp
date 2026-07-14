class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(string i : strs) {
            str += to_string(i.length()) + "#" + i; 
        }
        cout << str << endl;
        return str;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int len = 0;
        bool shuru = false;
        for(auto i : s) {
            if(shuru && len > 0) {
                strs.back() += i;
                len--;
            } else if(i == '#') {
                strs.push_back("");
                shuru = true;
            } else {
                shuru = false;
                len = len * 10 + (i - '0');
            }
        }

        return strs;
    }
};
