// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int num: arr) mp[num]++;
        int i = 1;

        while(i <= INT_MAX) {
            if(mp.find(i) == mp.end()) k--;
            if(k == 0) return i;
            i++;
        }

        return -1;
    }
};