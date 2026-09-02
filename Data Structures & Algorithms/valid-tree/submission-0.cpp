class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);    
            adj[edges[i][1]].push_back(edges[i][0]);    
        }

        queue<pair<int, int>> q;
        vector<bool> vis(n + 1, false);
        int cnt = 0;

        q.push({0, -1});
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            vis[curr.first] = true;
            cnt++;

            // cerr << endl << curr.first << " -> ";
            for(int nbr : adj[curr.first]) {
                // cerr << nbr << " ";
                if(nbr != curr.second) {
                    if(vis[nbr]) {
                        // cerr << "[" << curr.first << ", " << curr.second << "]" << " : " << nbr << endl;
                        return false;
                    }
                    q.push({nbr, curr.first});
                }
            }
        }

        cerr << cnt << endl;

        return cnt == n;
    }
};
