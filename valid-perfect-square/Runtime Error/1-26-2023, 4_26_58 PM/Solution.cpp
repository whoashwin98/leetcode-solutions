// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num/2;

        if(num == 1) return true;

        while(left <= right) {
            int mid = left + (right-left)/2;
            if(mid * mid == num) return true;
            else if(mid * mid > num) right = mid-1;
            else left = mid+1;
        }

        return false;
    }
};