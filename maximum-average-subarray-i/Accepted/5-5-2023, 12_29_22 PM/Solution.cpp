// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        double maxi = INT_MIN;

        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double avg = (double) sum / (double) k;
        maxi = max(maxi, avg);

        for(int i = k; i < nums.size(); i++) {
            sum -= nums[i-k];
            sum += nums[i];
            avg = (double) sum / (double) k;
            maxi = max(maxi, avg);
        }

        return maxi;
    }
};