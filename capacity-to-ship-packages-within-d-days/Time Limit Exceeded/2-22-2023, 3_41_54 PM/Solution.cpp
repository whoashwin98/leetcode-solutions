// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    bool isSafe(vector<int> weights, int days, int capacity) {
        int w = 0;
        int d = 1;
        cout << "For capacity: " << capacity << endl;
        for(int i=0; i<weights.size(); i++) {
            if(w + weights[i] > capacity) {
                d++;
                w = 0;
            }
            w += weights[i];
            cout << "Weights: " << w << endl;
            cout << "Days: " << d << endl;
        }
        return d > days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i=0; i<weights.size(); i++) {
            high += weights[i];
        }

        while(low < high) {
            int mid = low + (high-low) / 2;
            if(isSafe(weights, days, mid)) low = mid+1;
            else high = mid;
        }

        return low;
    }
};