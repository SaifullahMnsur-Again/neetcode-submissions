class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> stc;
        for(string i : tokens) {
            if(i == "+" || i == "-" || i == "/" || i == "*") {
                int b = stc.top(); stc.pop();
                int a = stc.top(); stc.pop();
                int val;
                if(i == "+") {
                    val = a + b;
                } else if(i == "*") {
                    val = a * b;
                } else if(i == "-") {
                    val = a - b;
                } else {
                    val = a / b;
                }
                stc.push(val);
            } else {
                stc.push(stoi(i));
            }
        }

        return stc.top();
    }
};
