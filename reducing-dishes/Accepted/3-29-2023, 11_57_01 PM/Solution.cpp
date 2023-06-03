// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        
        int cumsum = 0;
        int ans = 0;
        int cur = 0;
        
        for(int i = n-1; i >= 0; i--)
        {
            cur += cumsum + satisfaction[i];
            cumsum += satisfaction[i];
            ans = max(ans,cur);
        }
        
        return ans;
    }
};