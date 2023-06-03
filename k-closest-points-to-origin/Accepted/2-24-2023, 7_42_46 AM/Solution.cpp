// https://leetcode.com/problems/k-closest-points-to-origin

class compare {
    public: 
    bool operator()(pair<double, vector<int>>& a, pair<double, vector<int>>& b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>, vector<pair<double,vector<int>>>, compare> pq;

        for(auto point: points) {
            double dist = sqrt((point[0]*point[0])+ (point[1]*point[1]));
            pq.push({dist,point});
        }

        vector<vector<int>> ans;
        while(!pq.empty() && k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};