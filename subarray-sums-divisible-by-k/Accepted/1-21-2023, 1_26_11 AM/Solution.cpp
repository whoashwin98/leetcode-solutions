// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        int count = 0;
        mp[sum] = 1;
        int n = arr.size();

        for(int i=0; i < n; i++) {
            sum += arr[i];

            int rem = sum % k;
            if(rem < 0) rem += k;

            if(mp.find(rem) != mp.end()) count += mp[rem];

            mp[rem]++;
        }

        return count;
    }
};