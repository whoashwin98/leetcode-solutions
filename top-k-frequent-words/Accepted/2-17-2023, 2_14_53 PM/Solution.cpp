// https://leetcode.com/problems/top-k-frequent-words

class compare {
    public: 
    bool operator()(pair<string,int>& a, pair<string,int>& b) {
        if(a.second == b.second) return a.first > b.first;
        else return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string word: words) mp[word]++;

        priority_queue<pair<string,int>, vector<pair<string,int>>, compare> pq;
        for(auto it: mp) pq.push({it.first, it.second});

        vector<string> ans;
        while(!pq.empty() && ans.size() < k) {
            auto temp = pq.top();
            ans.push_back(temp.first);
            pq.pop();
        }
        
        return ans;
    }
};