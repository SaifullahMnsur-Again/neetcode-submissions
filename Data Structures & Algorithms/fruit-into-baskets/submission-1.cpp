class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        set<int> st;
        int ans = 0;
        map<int, int> mp;
        int curr = 0;
        while(r < fruits.size()) {
            if(r < fruits.size()) {
                mp[fruits[r]]++;
                st.insert(fruits[r]);
                curr++;
                r++;
            }
            while(2 < st.size()) {
                mp[fruits[l]]--;
                curr--;
                if(mp[fruits[l]] == 0)
                    st.erase(fruits[l]);
                l++;
            }
            ans = max(ans, curr);
        }

        return ans;
    }
};