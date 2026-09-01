class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; n > 0 and i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0) {
                if(i == 0 or (i > 0 and flowerbed[i - 1] == 0)) {
                    if(i == flowerbed.size() - 1 or (i < flowerbed.size() - 1 and flowerbed[i + 1] == 0)) {
                        n--;
                        flowerbed[i] = 1;
                    }
                }
            }
        }
        return n == 0;
    }
};