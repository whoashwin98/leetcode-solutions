// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int start = points[0][0];
        int end = points[0][1];
        int count = 1;
        bool isPair = false;

        for(int i=1; i<points.size(); i++) {
            if(points[i][0] <= end && !isPair) {
                start = min(start, points[i][0]);
                end = max(end, points[i][1]);
                isPair = true;
            }

            else {
                count++;
                start = points[i][0];
                end = points[i][1];
                isPair = false;
            }
        }

        return count;
    }
};