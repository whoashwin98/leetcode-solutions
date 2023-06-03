// https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0;
        unordered_map<string,int> mp;

        for(string num: nums) mp[num]++;

        for(int i=0; i<target.size(); i++) {
            string first = target.substr(0,i);
            string second = target.substr(i);

            if(first == second) count += mp[first] * (mp[second] - 1);
            else count += mp[first] * mp[second];
        }

        return count;
    }
};