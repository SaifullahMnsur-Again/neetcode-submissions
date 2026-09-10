class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto str : arr) 
            mp[str]++;
            
        for(auto i : arr) {
            if(mp[i] == 1) {
                if(k == 1)
                    return i;
                k--;
            }
        }
        return "";
    }
};