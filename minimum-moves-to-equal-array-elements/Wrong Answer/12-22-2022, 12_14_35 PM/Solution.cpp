// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums) {
            mp[num]++;
        }

        int maxCount = -1;
        for(auto p : mp) {
            cout << p.first << p.second << endl;
            maxCount = max(p.second,maxCount);
        }

        if(maxCount == 1) return nums.size();
        return nums.size()-maxCount;
    }
};