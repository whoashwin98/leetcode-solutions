// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int left = 0;
        int right = n-1;

        while(left < right) {
            int h = (height[left] < height[right]) ? height[left] : height[right];
            // cout << h << "$";
            int water = (right - left) * h;
            // cout << water << "%";
            ans = max(ans, water);
            // cout << ans << "#";
            if(h == height[left]) left++;
            else right--;
        }

        return ans;
    }
};