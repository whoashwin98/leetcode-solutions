// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> mp;

        for(int num: arr) mp[num]++;

        for(int i=1; i<=1000; i++) {
            if(mp.find(i) == mp.end()) k--;
            if(k == 0) return i;
        }

        return -1;
    }
};