class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stc;
        for(auto op : operations) {
            if(op == "+") {
                int a = stc.top(); stc.pop();
                int s = a + stc.top();
                stc.push(a);
                stc.push(s);
            } else if(op == "C") {
                stc.pop();
            } else if(op == "D") {
                int p = 2 * stc.top();
                stc.push(p);
            } else {
                stc.push(stoi(op));
            }
        }
        int sum = 0;
        while(!stc.empty()) {
            cerr << stc.top() << endl;
            sum += stc.top();
            stc.pop();
        }
        return sum; 
    }
};