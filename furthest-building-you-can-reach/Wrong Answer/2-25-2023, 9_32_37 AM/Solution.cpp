// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        for(int i=0; i<heights.size()-1; i++) {
            // cout << heights[i] << " " << bricks << " " << ladders << endl;
            if(heights[i] >= heights[i+1]) continue;
            if(bricks <= 0 && ladders <= 0) return i;
            int diff = (heights[i+1] - heights[i]);
            if(bricks >= diff) bricks -= diff;
            else ladders--;
        }
        return heights.size() - 1;
    }
};