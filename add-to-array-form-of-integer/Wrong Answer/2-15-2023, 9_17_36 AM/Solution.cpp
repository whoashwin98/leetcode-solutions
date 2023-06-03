// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = 0;

        for(int i = num.size() - 1; i>=0; i--) {
            int digit = (k % 10) + num[i] + carry;
            carry = digit / 10;
            digit = digit % 10;
            ans.push_back(digit);
            k /= 10;
        }

        if(k > 0) {
            ans.push_back(k % 10);
            k = k / 10;
        }

        if(carry > 0) {
            ans.push_back(carry);
            carry = carry / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};