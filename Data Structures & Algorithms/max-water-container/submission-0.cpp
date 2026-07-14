class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int maxx = 0, curr = 0;
        while(l < r) {
            curr = min(h[l], h[r]) * (r - l);
            maxx = max(maxx, curr);
            if(h[l] < h[r])
                l++;
            else
                r--;
        }
        return maxx;
    }
};
