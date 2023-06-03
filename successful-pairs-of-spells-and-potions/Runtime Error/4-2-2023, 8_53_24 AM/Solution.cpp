// https://leetcode.com/problems/successful-pairs-of-spells-and-potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());

        for(int i=0; i<n; i++) {
            int start = 0;
            while(start < potions.size() && spells[i] * potions[start] < success) start++;
            ans[i] = m  - start;
        }

        return ans;
    }
};