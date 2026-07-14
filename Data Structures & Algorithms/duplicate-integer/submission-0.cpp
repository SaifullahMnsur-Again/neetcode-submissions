class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> ust;
        for(auto &i : nums) {
            if(ust.find(i) != ust.end())
                return true;
            ust.insert(i);
        }
        return false;
    }
};