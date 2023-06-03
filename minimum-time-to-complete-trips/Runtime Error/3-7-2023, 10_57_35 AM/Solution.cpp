// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
    bool isSafe(vector<int>& time, int totalTrips, int totalTime) {
        long long trips = 0;

        for(int i=0; i<time.size(); i++) {
            trips += totalTime / time[i];
        }

        return trips < totalTrips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = *min_element(time.begin(), time.end()) * totalTrips;

        while(low < high) {
            long long mid = low + (high-low) / 2;
            if(isSafe(time, totalTrips, mid)) low = mid+1;
            else high = mid;
        }

        return low;
    }
};