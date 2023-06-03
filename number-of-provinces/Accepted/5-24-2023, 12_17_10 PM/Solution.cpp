// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void bfs(int n, vector<int> adj[], vector<int>& vis, int src) {
        queue<int> q;
        q.push(src);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            vis[node] = 1;

            for(auto neigh : adj[node]) {
                if(!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        vector<int> vis(n+1, 0);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                ans++;
                bfs(n, adj, vis, i);
            }
        }

        return ans;
    }
};