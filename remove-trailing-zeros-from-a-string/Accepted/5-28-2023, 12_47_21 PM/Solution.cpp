// https://leetcode.com/problems/remove-trailing-zeros-from-a-string

class Solution {
public:
    string removeTrailingZeros(string num) {
        int last = num.size()-1;
        while(last >= 0){
            if(num[last] != '0') break;
            last--;
        } 

        string ans = "";
        for(int i=0; i<=last; i++) ans.push_back(num[i]);
        return ans;
    }
};