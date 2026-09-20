class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int l = 0, r = 0;
        int ls = 0, rs = 0;
        for(int i = 1; i < n; i++) {
            if(boxes[i] == '1') {
                r++;
                rs += i;
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(ls + rs);
            rs -= r;
            if(boxes[i] == '1')
                l++;
            if(i < n - 1 and boxes[i + 1] == '1')
                r--;
            ls += l;
        }
        return ans;
    }
};