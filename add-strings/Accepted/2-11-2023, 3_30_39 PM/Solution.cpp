// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        int i = m-1, j = n-1;
        
        int carry = 0;
        string ans = "";
        while(i >= 0 && j >=0) {
            int curr = (num1[i] - '0') + (num2[j] - '0') + carry;
            carry = curr / 10;
            curr = curr % 10;
            ans.push_back('0' + curr);
            i--;
            j--;
        }

        while(i >= 0) {
            int curr = (num1[i] - '0') + carry;
            carry = curr / 10;
            curr = curr % 10;
            ans.push_back('0' + curr);
            i--;
        }

        while(j >= 0) {
            int curr = (num2[j] - '0') + carry;
            carry = curr / 10;
            curr = curr % 10;
            ans.push_back('0' + curr);
            j--;
        }

        while(carry > 0) {
            ans.push_back(carry + '0');
            carry = 0;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};