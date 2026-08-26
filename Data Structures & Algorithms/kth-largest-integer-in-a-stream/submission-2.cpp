class KthLargest {
    int k;
    multiset<int> nums;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i : nums)
            this->nums.insert(i);
        while(this->nums.size() > k)
            this->nums.erase(this->nums.begin());
    }
    
    int add(int val) {
        nums.insert(val);
        if(nums.size() > k)
            nums.erase(nums.begin());
        return *nums.begin();
    }
};
