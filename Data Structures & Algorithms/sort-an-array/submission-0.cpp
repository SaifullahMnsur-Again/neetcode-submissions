class Solution {
    void margeSort(vector<int> &nums, int l, int r) {
        if(l >= r)
            return;
        
        int mid = l + (r - l) / 2;
        
        margeSort(nums, l, mid);
        margeSort(nums, mid + 1, r);
        int ll = l;
        int rr = mid + 1;

        vector<int> temp;

        while(ll <= mid and rr <= r) {
            if(nums[ll] < nums[rr]) {
                temp.push_back(nums[ll++]);
            } else {
                temp.push_back(nums[rr++]);
            }
        }
        while(ll <= mid) {
            temp.push_back(nums[ll++]);
        }
        while(rr <= r) {
            temp.push_back(nums[rr++]);
        }
        for(int i = l; i <= r; i++)
            nums[i] = temp[i - l];
        
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        margeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};