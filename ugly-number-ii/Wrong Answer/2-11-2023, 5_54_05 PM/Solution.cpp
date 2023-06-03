// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly;
        for(int i=1; i<=1690; i++) {
            if(i == 1 || i % 2 == 0 || i % 3 == 0 || i % 5 == 0) ugly.push_back(i);
        }
        return ugly[n-1];
    }
};