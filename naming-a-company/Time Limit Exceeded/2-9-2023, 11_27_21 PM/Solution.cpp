// https://leetcode.com/problems/naming-a-company

class Solution {
public:
    void swap(vector<string>& ideas, int i, int j) {
        string first = ideas[i];
        string second = ideas[j];

        char temp = first[0];
        first[0] = second[0];
        second[0] = temp;

        ideas[i] = first;
        ideas[j] = second;
    }

    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, int> mp;
        long long ans = 0;
        for(string idea : ideas) mp[idea]++;

        int n = ideas.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                swap(ideas, i, j);
                if(mp[ideas[i]] == 0 && mp[ideas[j]] == 0) ans += 2;
                swap(ideas, i, j);
            }
        }

        return ans;
    }
};