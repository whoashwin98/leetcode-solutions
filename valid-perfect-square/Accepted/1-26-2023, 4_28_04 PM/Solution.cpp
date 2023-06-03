// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int left = 1;
        long long int right = num;

        if(num == 1) return true;

        while(left <= right) {
            long long int mid = left + (right-left)/2;
            if(mid * mid == num) return true;
            else if(mid * mid > num) right = mid-1;
            else left = mid+1;
        }

        return false;
    }
};