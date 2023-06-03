// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if(n < 2) return false;

        unordered_map<int,int> mp;
        int sum = 0;
        mp[sum] = -1;

        for(int i=0; i<n; i++) {
            sum += arr[i];
            if(k != 0) sum = sum % k;

            if(mp.find(sum) != mp.end()) {
                if(i - mp[sum] > 1) return true;
            }

            else mp[sum] = i;
        }

        return false;
    }
};