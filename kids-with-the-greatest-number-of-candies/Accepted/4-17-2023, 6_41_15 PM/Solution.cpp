// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n, false);
        int maxCandies = *max_element(candies.begin(), candies.end());

        for(int i=0; i<n; i++) {
            if(candies[i] + extraCandies >= maxCandies) ans[i] = 1;
        }

        return ans;
    }
};