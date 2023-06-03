class Solution
{
public:
    int solve(unordered_map<int, list<pair<int, int>>> &mp, int parent)
    {
        if (mp.find(parent) == mp.end())
            return 0;

        int ans = 0;
        for (auto child : mp[parent])
        {
            ans = max(ans, child.second + solve(mp, child.first));
        }

        return ans;
    }

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        int ans = 0;
        unordered_map<int, list<pair<int, int>>> mp;

        for (int i = 0; i < n; i++)
        {
            mp[manager[i]].push_back({i, informTime[i]});
        }

        ans = solve(mp, -1);
        return ans;
    }
};