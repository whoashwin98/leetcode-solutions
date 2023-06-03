// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int left = 0;   
        int n = haystack.size();
        int m = needle.size();

        while(left < n-m) {
            int i = left;
            while(haystack[i] == needle[i]) i++;
            if(i-left == m) return left; 
            left++;
        }

        return -1;
    }
};