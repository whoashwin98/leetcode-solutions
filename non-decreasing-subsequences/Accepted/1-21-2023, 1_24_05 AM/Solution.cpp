// https://leetcode.com/problems/non-decreasing-subsequences

class Solution {
    void solve(vector<int>& nums, vector<int>& sequence, set<vector<int>>& result, int i) {
        // if we have checked all elements
        if (i == nums.size()) {
            if (sequence.size() >= 2) result.insert(sequence);
            return;
        }

        // if the sequence remains increasing after appending nums[index]
        if (sequence.empty() || sequence.back() <= nums[i]) {
            // append nums[index] to the sequence
            sequence.push_back(nums[i]);
            // call recursively
            solve(nums, sequence, result, i+1);
            // delete nums[index] from the end of the sequence
            sequence.pop_back();
        }

        // call recursively not appending an element
        solve(nums, sequence, result, i+1);
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> sequence;
        function<void(int)> backtrack;
        solve(nums, sequence, result, 0);
        return vector(result.begin(), result.end());
    }
};