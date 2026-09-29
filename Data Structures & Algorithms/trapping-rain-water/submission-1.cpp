class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> toLeft(h.size()), toRight(h.size());
        for(int i = 0, j = h.size() - 1; i < h.size(); i++, j--) {
            if(i == 0) {
                toLeft[i] = 0;
                toRight[j] = 0;
            } else {
                toLeft[i] = max(h[i - 1], toLeft[i - 1]);
                toRight[j] = max(h[j + 1], toRight[j + 1]);
            }
        }
        // for(int i = 0; i < h.size(); i++) {
        //     cerr << toLeft[i] << " ";
        // } cerr << endl;
        // for(int j = 0; j < h.size(); j++) {
        //     cerr << toRight[j] << " ";
        // } cerr << endl;

        int sum = 0;
        for(int i = 0; i < h.size(); i++) {
            sum += max(min(toLeft[i], toRight[i]) - h[i], 0);
            // cerr << sum << " ";
        }

        return sum;
    }
};
