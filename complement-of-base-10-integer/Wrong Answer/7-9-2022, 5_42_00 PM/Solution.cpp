// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        int i;
        if(n==0) return 1;
        for(i=1; i<n; i*=2);
        return i-1-n;
    }
};