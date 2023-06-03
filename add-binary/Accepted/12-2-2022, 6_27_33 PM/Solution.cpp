// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans = "";

        while(i >=0 && j >= 0) {
            int digit = (a[i] - '0') + (b[j] - '0') + carry;
            if(digit > 1) {
                carry = digit / 2;
                digit = digit % 2;
            }
            else {
                carry = 0;
            }
            ans.push_back(digit + '0');
            i--;
            j--;
        }

        while(i >=0) {
            int digit = (a[i] - '0') + carry;
            if(digit > 1) {
                carry = digit / 2;
                digit = digit % 2;
            }
            else {
                carry = 0;
            }
            ans.push_back(digit + '0');
            i--;
        }

        while(j >= 0) {
            int digit = (b[j] - '0') + carry;
            if(digit > 1) {
                carry = digit / 2;
                digit = digit % 2;
            }
            else {
                carry = 0;
            }
            ans.push_back(digit + '0');
            j--;
        }




        if(carry > 0) ans.push_back(carry + '0');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};