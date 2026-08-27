class Solution {
public:
    bool isPathCrossing(string path) {
        map<int, map<int, bool>> vis;
        pair<int, int> coord = {0, 0};
        vis[0][0] = true;

        for(char c : path) {
            if(c == 'N') {
                coord.second++;
            } else if (c == 'S') {
                coord.second--;
            } else if(c == 'W') {
                coord.first--;
            } else {
                coord.first++;
            }
            if(vis[coord.first][coord.second]) {
                return true;
            }
            vis[coord.first][coord.second] = true;
        }
        
        return false;
    }
};