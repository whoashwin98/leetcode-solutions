// https://leetcode.com/problems/top-k-frequent-elements

class compare
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second<b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int num : nums) mp[num]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        
        for(auto it: mp) pq.push({it.first, it.second});

        vector<int> ans;
        for(int i=0; i<k && !pq.empty(); i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;   
    }
};