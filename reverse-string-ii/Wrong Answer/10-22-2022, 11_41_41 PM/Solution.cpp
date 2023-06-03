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
    
    string reverseStr(string s, int k) {
        for(int i=0; i<s.size(); i+=k*2) {
            reverseUtil(s,i,i+k-1);
        }
        
        return s;
    }
};