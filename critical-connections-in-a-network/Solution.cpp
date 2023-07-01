class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it : adj[node]) {
            if(it == parent) continue;

            // node not visited
            if(!vis[it]) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // check if it can be a bridge
                if(low[it] > tin[node]) bridges.push_back({node, it});
            }

            // node already visited (same component)
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // create the adjacency list from the given list of edges
        vector<int> adj[n];
        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};
