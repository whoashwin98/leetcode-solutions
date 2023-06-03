// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool isValid(vector<int> piles, int h, int bph) {
        long long time = 0;

        // idea here is to find the time taken to finish each pile 
        // by dividing current element by the number of bananas that can be eaten per hour(bph)
        // if any remainder is obtained on division, that means either pile is less than 
        // bph or if it is more, bph does not evenly divide it. in this case, we increment the
        // answer by 1 so that the count for the remaining bananas to be eaten is considered.

        for(int pile: piles) {
            if(pile % bph > 0) time++;
            time += pile/bph;
        }

        // if the answer comes out to be less than or equal to the given time, return true
        return time <= h;
    }
    

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1e9;
        int ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(isValid(piles,h,mid)) {
                ans = mid;
                // to get the minimum answer we have to move to the left side
                // of the search space
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};