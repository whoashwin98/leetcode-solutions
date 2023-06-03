// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
    bool isSafe(vector<int>& time, int totalTrips, long long int totalTime) {
        long long int trips = 0;

        for(int i=0; i<time.size(); i++) {
            trips += totalTime / time[i];
        }

        return trips < totalTrips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low = 1;
        long long int high = 1e14;

        while(low < high) {
            long long int mid = low + (high-low) / 2;
            if(isSafe(time, totalTrips, mid)) low = mid+1;
            else high = mid;
        }

        return low;
    }
};