// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int trapped = 0;
        int n = height.size();
        int maxLeft = height[0];
        int maxRight = height[n-1];

        int left=0, right=n-1;

        while(left <= right) {
            if(height[left] <= height[right]) {
                if(maxLeft <= height[left]) maxLeft = height[left];
                else trapped += maxLeft - height[left];
                left++;
            }

            else {
                if(maxRight <= height[right]) maxRight = height[right];
                else trapped += maxRight - height[right];
                right--;
            }
        }
        return trapped;
    }
};