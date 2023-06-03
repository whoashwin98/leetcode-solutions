// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int left = 0;   
        int n = haystack.size();
        int m = needle.size();

        if(haystack == needle) return 0;

        while(left < n) {
            string cmp = haystack.substr(left, m);
            if(cmp == needle) return left;
            else left++;
        }

        return -1;
    }
};