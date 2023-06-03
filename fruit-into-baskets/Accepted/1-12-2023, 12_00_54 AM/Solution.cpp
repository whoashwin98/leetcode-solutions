// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;

        int n = fruits.size();

        unordered_map<int,int> mp;

        while(right < n) {    
            mp[fruits[right]]++;

            if(mp.size() > 2) { 
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }
            right++;
        }
        
        return right - left;
    }
};