class Solution {
public:
    bool isHappy(int n) {
        vector<bool> vis(1001, false);

        while(n > 1) {
            int t = 0;
            while(n > 0) {
                t += (n%10) * (n%10);
                n /= 10;
            }
            n = t;
            if(n > 1000)
                return false;
            if(vis[n])
                return false;
            vis[n] = true;
        }

        return true;
    }
};
