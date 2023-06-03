// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;

        unordered_map<int,bool> vis;
        int n = fruits.size();

        int ans = 0;
        int k = 0;

        while(right < n) {    
            if(vis.find(fruits[right]) == vis.end() && k < 2) {
                vis[fruits[right]] = true;
                k++;
            }

            if(k == 2 && !vis[fruits[right]]) {
                vis.erase(fruits[left]);
                left++;
                vis[fruits[right]] = true;
            }
            
            ans = max(ans, right-left+1);
            right++;
        }
        
        return ans;
    }
};