// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    int maxPoints(vector<vector<int>>& arr) {
        int maxBalloons = 0;
                
        for (int i = 0; i < arr.size(); i++) {
            int x1 = arr[i][0];
            int y1 = arr[i][1];
            unordered_map<double,int> mp;
            int count = 0;
            for (int j = 0; j < arr.size(); j++) {
                int x2 = arr[j][0];
                int y2 = arr[j][1];
                
                if(x1 == x2 && y1 == y2) {
                    count++;
                    continue;
                }
                double slope = (double)(y2-y1) / (double)(x2-x1);
                mp[slope]++;
            }
            
            for(auto it : mp) {
                maxBalloons = max(maxBalloons, it.second + count);
            }

        }

        return maxBalloons;
    }
};