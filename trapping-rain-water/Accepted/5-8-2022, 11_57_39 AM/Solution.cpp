// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int trapped = 0;
        int n = height.size();
        int maxLeft = height[0];
        int maxRight = height[n-1];

        int left=0, right=n-1;

        while(left < right) {
            if(maxLeft < maxRight) {
                left++;
                maxLeft = max(maxLeft,height[left]);
                trapped += maxLeft - height[left];
            }

            else {
                right--;
                maxRight = max(maxRight,height[right]);
                trapped += maxRight - height[right];
            }
        }

        return trapped;
    }
};