// https://leetcode.com/problems/reverse-string-ii

class Solution {
public:
    void reverseUtil(string &str, int s, int e) {
        while(s < e) {
            swap(str[s], str[e]);
            s++;
            e--;
        }
    }
    
    string reverseStr(string str, int k) {
        if(str.size() < k) {
            reverseUtil(str,0,str.size() - 1);
            return str;
        }
        
        int s = 0, e = k-1;
        while(e < str.size()) {
            reverseUtil(str,s,e);
            s += 2 * k;
            e = s + k - 1;
        }
        
        return str;
    }
};