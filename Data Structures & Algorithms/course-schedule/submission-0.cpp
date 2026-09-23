class Solution {
    bool dfs(int cr, vector<vector<int>>& adj, vector<int> &vis) {
        if(vis[cr] == 1)
            return true;
        if(vis[cr] == 2)
            return false;
        
        vis[cr] = 1;
        for(auto nbr : adj[cr]) {
            if(dfs(nbr, adj, vis))
                return true;
        }
        vis[cr] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int end = numCourses - 1;
        vector<vector<int>> adj(numCourses);
        for(auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(numCourses, false);
        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0)
                if(dfs(i, adj, vis))
                    return false;
        }
        return true;
    }
};
