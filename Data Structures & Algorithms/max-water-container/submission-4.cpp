class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int area = 0;
        while(r - l > 0) {
            int curr = (r - l) * min(heights[l], heights[r]);
            area = max(area, curr);
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }

        return area;
    }
};
