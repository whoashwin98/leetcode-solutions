// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        // will eventually store the number of nodes in the graph - 1
        int maxi = -1;

        for(int i=0; i<edges.size(); i++) {
            mp[edges[i][1]]++;
            maxi = max(maxi, max(edges[i][0], edges[i][1]));
        }

        vector<int> ans;
        for(int i=0; i<=maxi; i++) {
            if(mp.find(i) == mp.end()) ans.push_back(i);
        }
        return ans;
    }
};