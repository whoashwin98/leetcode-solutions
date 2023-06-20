class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for(int i=0; i<nums.size(); i++) {
            if(i-k < 0 || i + k >= nums.size()) {
                ans.push_back(-1);
                continue;
            }

            else {
                long long currSum = (i-k == 0) ? prefixSum[i+k] : prefixSum[i+k] - prefixSum[i-k-1];
                long long size = (i+k) - (i-k) + 1;
                ans.push_back(currSum / size);
            }
        }

        return ans;
    }
};