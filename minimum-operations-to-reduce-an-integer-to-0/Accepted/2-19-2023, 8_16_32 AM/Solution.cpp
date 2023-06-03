// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0

class Solution {
public:
    bool isPowerOfTwo(int x) {
        int dummy = 1;
        while(dummy < (INT_MAX / 2)) {
            if(dummy == x) return true;
            dummy = dummy << 1;
        }
        return false;
    }
    
    int minOperations(int n) {
        if(isPowerOfTwo(n)) return 1;
        
        int lessN = 1, greaterN = 1;
        while(greaterN <= n) {
            greaterN = greaterN << 1;
        }
        lessN = greaterN >> 1;
        
        int diff = 0;
        
        if((greaterN - n) < (n - lessN)) diff = greaterN - n;
        else diff = n - lessN;
        
        return 1 + minOperations(diff);
    }
};