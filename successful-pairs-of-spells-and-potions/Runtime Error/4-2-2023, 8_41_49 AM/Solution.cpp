// https://leetcode.com/problems/successful-pairs-of-spells-and-potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j < potions.size(); j++) {
                if(potions[j] * spells[i] >= success) count++;
            }
            ans[i] = count;
        }

        return ans;
    }
};