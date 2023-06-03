// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int h = min(height[i], height[j]);
                ans = max(ans, h * (j-i));
            }
        }

        return ans;
    }
};