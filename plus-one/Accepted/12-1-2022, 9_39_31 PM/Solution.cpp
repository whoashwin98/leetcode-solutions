// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        for(int i=digits.size() - 1; i>=0; i--) {
            int place = carry + digits[i];
            ans.push_back(place % 10);
            carry = place / 10;
        }

        if(carry > 0) {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};