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

        if(nums.size() == maxCount) return 0;
        return nums.size()-maxCount+1;
    }
};