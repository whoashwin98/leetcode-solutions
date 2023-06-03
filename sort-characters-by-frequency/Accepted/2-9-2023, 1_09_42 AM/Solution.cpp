// https://leetcode.com/problems/sort-characters-by-frequency

class compare
{
public:
    bool operator()(pair<char,int> a, pair<char,int> b)
    {
        return a.second<b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(char ch : s) mp[ch]++;

        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;
        for(auto it: mp) pq.push({it.first, it.second});

        string ans = "";
        while(!pq.empty()) {
            pair<char, int> temp = pq.top();
            pq.pop();

            int count = temp.second;
            char ch = temp.first;
            while(count > 0) {
                ans.push_back(ch);
                count--;
            }
        }

        return ans;
    }
};