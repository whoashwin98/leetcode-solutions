class Solution {

public:
    bool bfs(int src, vector<int>& vis, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(src);
        vis[src] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto neigh : graph[node]) {
                if(vis[neigh] == -1) {
                    q.push(neigh);
                    vis[neigh] = !vis[node];
                }

                else if(vis[neigh] == vis[node]) return false;
            }
        }

        return true;
    }

    bool dfs(int src, int col, vector<int>& vis, vector<vector<int>>& graph) {
        vis[src] = col;
        col = (1-col) % 2;

        for(auto neigh: graph[src]) {
            if(vis[neigh] == -1) {
                if(!dfs(neigh, col, vis, graph)) return false;
            }

            else if(vis[neigh] == vis[src]) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i=0; i<n; i++) {
            if(vis[i] == -1) {
                if(!dfs(i, 0, vis, graph)) return false;
            }
        }

        return true;
    }
};