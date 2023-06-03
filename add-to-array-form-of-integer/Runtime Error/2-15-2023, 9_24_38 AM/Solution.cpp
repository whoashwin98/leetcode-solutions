// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int x = 0;
        for(int i = 0; i<num.size(); i++) {
            x = x * 10 + num[i];
        }

        int sum = x + k;
        vector<int> ans;

        while(sum > 0) {
            ans.push_back(sum % 10);
            sum = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};