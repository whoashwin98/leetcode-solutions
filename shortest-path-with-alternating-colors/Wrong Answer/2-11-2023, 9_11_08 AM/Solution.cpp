// https://leetcode.com/problems/shortest-path-with-alternating-colors

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, list<pair<int,int>>> adj;

        // 0 = red
        for(int i=0; i<redEdges.size(); i++) {
            adj[redEdges[i][0]].push_back({redEdges[i][1], 0});
        }
        
        //1 = blue
        for(int i=0; i<blueEdges.size(); i++) {
            adj[blueEdges[i][0]].push_back({blueEdges[i][1], 1});
        }

        queue<int> q;
        vector<int> ans;
        q.push(0);
        bool isRed = true;

        while(!q.empty()) {
            int src = q.front();
            q.pop();

            ans.push_back(src);

            for(auto dest : adj[src]) {
                if((isRed && dest.second == 0) || (!isRed && dest.second == 1)) {
                    q.push(dest.first);
                }
            }
            isRed = !isRed;
        }

        int i = ans.size();
        while(i < n) {
            ans.push_back(-1);
            i++;
        }

        return ans;
    }
};