// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> ans;
        if(pairs.empty())
            return ans;
        ans.push_back(pairs);
        int n = pairs.size();
        for(int i = 1; i < n; i++) {
            Pair pair = pairs[i];
            int j = i - 1;
            while(j >= 0 and pairs[j].key > pair.key) {
                pairs[j + 1] = pairs[j];
                j--;
            }
            pairs[j + 1] = pair;
            ans.push_back(pairs);
        }

        return ans;
    }
};
