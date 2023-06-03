// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
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

        int ans = 1;
        for(int i=0; i<n; i++) {
            if(adj[i].empty()) ans++;
        }

        if(ans == n+1) ans--;
        return ans;
    }
};