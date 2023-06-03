// https://leetcode.com/problems/minimize-maximum-of-array

class Solution {
public:
    int minimizeArrayValue(vector<int>& A) {
        long sum = 0, ans = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            ans = max(ans, (sum + i) / (i + 1));
        }
        return ans;
    }
};