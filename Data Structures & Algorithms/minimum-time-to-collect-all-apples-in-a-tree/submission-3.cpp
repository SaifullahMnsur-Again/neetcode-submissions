class Solution {
    int dfs(int root, int par, vector<vector<int>> &adj, vector<bool>& hasApple) {
        int time = 0;
        for(auto nbr: adj[root]) {
            if(nbr != par) {
                int child = dfs(nbr, root, adj, hasApple);
                if(child > 0 || hasApple[nbr]) {
                    time += child + 2;
                }
            }
        }
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};