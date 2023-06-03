// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        int i;        
        for(i=1; i < n; i = i<<1);
        int mask = i-1;
        return (~n)&mask;
    }
};