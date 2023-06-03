// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i=0; i<weights.size(); i++) {
            high += weights[i];
        }

        while(low < high) {
            int mid = low + (high-low) / 2;

            int w = 0;
            int d = 1;
            for(int i=0; i<weights.size(); i++) {
                if(w + weights[i] > mid) {
                    d++;
                    w = 0;
                }
                w += weights[i];
            }

            if(d > days) low = mid+1;
            else high = mid;
        }

        return low;
    }
};