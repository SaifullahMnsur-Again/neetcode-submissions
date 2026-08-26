#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, 
             less_equal<int>, 
             rb_tree_tag, 
             tree_order_statistics_node_update> 
ordered_multiset;

class KthLargest {
    int k;
    ordered_multiset nums;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i : nums)
            this->nums.insert(i);
    }
    
    int add(int val) {
        nums.insert(val);
        return *nums.find_by_order(nums.size() - k);
    }
};
