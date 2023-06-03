// https://leetcode.com/problems/shortest-path-with-alternating-colors

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, list<pair<int,int>>> adj;

        // 0 = red
        for(int i=0; i<redEdges.size(); i++) {
            adj[redEdges[i][0]].push_back({redEdges[i][1], 0});
        }
        
        // 1 = blue
        for(int i=0; i<blueEdges.size(); i++) {
            adj[blueEdges[i][0]].push_back({blueEdges[i][1], 1});
        }

        vector<int> ans(n,-1);
        queue<vector<int>> q;
        q.push(vector<int>{0,0,-1});
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            // find the distance of the current node
            ans[front[0]] = ans[front[0]] != -1 ? ans[front[0]] : front[1];
            
            for(auto &dest : adj[front[0]]) {
				//Push the node to the queue only if the next edge color is different from the pervious edge color and also if we are visiting the edge
				//for the first time.
                if(front[2] != dest.second && dest.first != -1) {
                    q.push(vector<int>{dest.first, front[1] + 1, dest.second});
					//Update the value in the adjacency matrix to -1 to denote that the node has already been visited.
                    dest.first = -1;
                }
            }
        }

        return ans;
    }
};