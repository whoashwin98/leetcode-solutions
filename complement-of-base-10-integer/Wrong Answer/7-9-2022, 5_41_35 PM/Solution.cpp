// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        int i;
        for(i=1; i<n; i*=2);
        return i-1-n;
    }
};